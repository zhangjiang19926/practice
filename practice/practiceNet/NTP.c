#include <sys/socket.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

struct NTPPacket
{
	char Leap_Ver_Mode;	
	char Startum;
	char Poll;
	char Precision;
	double RootDelay;
	double Dispersion;
	char RefIdentifier[4];
	char RefTimeStamp[8];
	char OriTimeStamp[8];
	char RecvTimeStamp[8];
	char TransTimeStamp[8];
};
	
#define NTPPORT 123
#define TIMEPORT 37
#define NTPV1 "NTP/V1"
#define NTPV2 "NTP/V2"
#define NTPV3 "NTP/V3"
#define NTPV4 "NTP/V4"
#define TIME  "TIME/UDP"

double SecondBef1970;
struct sockaddr_in SinLen;
struct addrinfo hints, *res = NULL;
int rc, sk;
char Protocol[32];

int ConstuctPacket(char *Packet)
{
	char Version = 1;
	long SecondFrom1900;
	long Zero = 0;
	int Port;
	time_t timer;
	strcpy(Protocol, NTPV1);
	if (strcmp(Protocol, NTPV1) || strcmp(Protocol, NTPV2) || strcmp(Protocol, NTPV3) || strcmp(Protocol, NTPV4) )
	{
		Port = NTPPORT;
		Version = Protocol[6] - 0x30;
		Packet[0] = (Version << 3) | 3;
		Packet[1] = 0;
		Packet[2] = 0;
		Packet[3] = 0;
		memset(&Packet[4], 0, 12);
		time(&timer);
		SecondFrom1900 = SecondBef1970 + (long)timer;
		SecondFrom1900 = htonl(SecondFrom1900);
		memcpy(&Packet[40], &SecondFrom1900, 4);
		memcpy(&Packet[44], &Zero, 4);
		return 48;
	}
	else 
	{
		Port = TIMEPORT;
		memset(Packet, 0, 4);
		return 4;
	}
	return 0;
}

long GetSecondFrom1900(int End)
{
	int Ordinal = 0;
	int Run = 0;
	long Result;
	int i;
	for (i = 1900; i < End; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			Run++;
		else 
			Ordinal++;
	}
	Result = (Run * 366 + Ordinal * 365) * 24 * 3600;
	return Result;
}

long GetNtpTime(int sk, struct addrinfo *res)
{
	char Content[256];
	int PacketLen;
	fd_set PendingData;
	struct timeval BlockTime;
	int FromLen;
	int Count = 0;
	int result, i;
	int re;
	struct NTPPacket RetTime;
	PacketLen = ConstuctPacket(Content);
	if (!PacketLen)
		return 0;
	if ((result = sendto(sk, Content, PacketLen, 0, res -> ai_addr, res -> ai_addrlen)) < 0)
	{
		perror("sendto");
	}
	else 
		printf("sendto success result = %d\n", result);
	for (i = 0; i < 5; i++)
	{
		printf("in for \n");
		FD_ZERO(&PendingData);
		FD_SET(sk, &PendingData);
		BlockTime.tv_sec = 1;
		BlockTime.tv_usec = 0;
		if (select(sk + 1, &PendingData, NULL, NULL, &BlockTime) > 0)
		{
			FromLen = sizeof(SinLen);
			if ((Count = recvfrom(sk, Content, 256, 0, res -> ai_addr, &(res -> ai_addrlen))) < 0)
				perror("recvfrom");
			else 
				printf("recvfrom success, Count = %d\n", Count);
			if (Protocol == TIME)
			{
				memcpy(RetTime.TransTimeStamp, Content, 4);
				return 1;
			}
			else if (Count >= 48 && Protocol != TIME) 
			{
				RetTime.Leap_Ver_Mode = Content[0];		
				RetTime.Startum = Content[1];
				RetTime.Poll = Content[2];
				RetTime.Precision = Content[3];
				memcpy((void *)&RetTime.RootDelay, &Content[4], 4);
				memcpy((void *)&RetTime.Dispersion, &Content[8], 4);
				memcpy((void *)&RetTime.RefIdentifier, &Content[12], 4);
				memcpy((void *)&RetTime.RefTimeStamp, &Content[16], 8);
				memcpy((void *)&RetTime.OriTimeStamp, &Content[24], 8);
				memcpy((void *)&RetTime.RecvTimeStamp, &Content[32], 8);
				memcpy((void *)&RetTime.TransTimeStamp, &Content[40], 8);
				return 1;
			}
		}
	}
	close(sk);
	return 0;
}

int main (int argv, char **argc)
{
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	rc = getaddrinfo("200.205.253.254", "123", &hints, &res);
	if (rc != 0)
	{
		perror("getaddrinfo");
		return;
	}
	sk = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);
	if (sk < 0)
	{
		perror("socket");
	}
	else 
		printf("socket success!\n");
	GetNtpTime(sk, res);
}
