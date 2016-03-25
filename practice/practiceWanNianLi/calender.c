#include <stdio.h>
#include <stdlib.h>

void display(int week, int month);

int main(int a, char **date)
{
	int d = 1, flag = 1, ru = 0, dm, days, dy = 0;
	int month = 0, year = 0;
	int dmy;
	int i = 0;
	while (date[1][i])//find the month and year
	{
		if ((date[1][i] == '/' || date[1][i] == '.') && d == 1)
		{
			d = 0;	
			++i;
		}
		if (d == 0)
			month = month * 10 + ( date[1][i] - '0' );
		if (d == 1)
			year = year * 10 + ( date[1][i] - '0' );
		++i;
	}	
	if (month < 1 || month > 12)
	{
		printf("error you input a wrong month\n");
		exit(1);
	}
	if (year > 2000)	
		dy = (year - 1 -2000) / 4 - (year - 1 -2000) / 100 + (year - 1 - 2000) / 400;
	else 
		dy = (year - 2000) / 4 - (year - 2000) / 100 + (year - 2000) / 400 - 1;
	dy = year - 2000 + dy;
	if (((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0)
		ru = 1;
	switch (month)
	{
		case 1: dm = 0; days = 31; break;	
		case 2: dm = 3; days = (ru == 1? 29:28); break; 	
		case 3: dm = 3 + ru; days = 31; break;	
		case 4:	dm = 6 + ru; days = 30; break;
		case 5:	dm = 1 + ru; days = 31; break;
		case 6: dm = 4 + ru; days = 30; break;	
		case 7: dm = 6 + ru; days = 31; break;	
		case 8: dm = 2 + ru; days = 31; break;	
		case 9:	dm = 5 + ru; days = 30; break;	
		case 10: dm = ru; days = 31; break;	
		case 11: dm = 3 + ru; days = 30; break;	
		case 12: dm = 5 + ru; days = 31; break;	
		default:exit(1);
	}
	dmy = dm + dy;
	display(dmy, days);	
	return 0;
}

void display(int week, int month)
{
	int i, j = 0;
	week = week + 6;
	week = ++week % 7;	
	printf("//**************************************************//\n");
	printf("Sun\tMon\tTues\tWed\tThur\tFri\tSat\n");
	for (i = 0; i < week; ++i)	
	{
		printf(" \t");
		++j;
	}
	for (i = 0; i < month; ++i)
	{
		printf("%d\t", i + 1);
		++j;
		if (j == 7)
		{
			printf("\n");
			j = 0;
		}
	}
	printf("\n//*************************************************//\n");
}

//int *calculate(int i, char **date)
//{
	//int d = 1, flag = 1, ru = 0, dm, days, dy;
	//int month, year;
	//int dmy[2];
	//while (date[1][i])	
	//{
		//if ((date[1][i] == "/" || date[1][i] == ".") && d == 1)
		//{
			//d = 0;	
			//++i;
		//}
		//if (i == 0)
			//month = month * 10 + ( date[1][0] - '0' );
		//if (d == 1)
			//year = year * 10 + ( date[1][i] - '0');
	//}	
	//if (month < 1 || month > 12)
	//{
		//printf("error you input a wrong month\n");
		//exit(1);
	//}
	//if (year == 2000)	
	//{
		//flag = 0;
		//ru = 1;	
	//}
	//if (flag == 1)
	//{
		//if (year > 2000)	
			//dy = (year - 1 -2000) / 4 - (year - 1 -2000) / 100 + (year - 1 - 2000) / 400;
		//else 
			//dy = (year - 2000) / 4 - (year - 2000) / 100 + (year - 2000) / 400;
		//dy = year + 2000 + dy;
		//if (((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0)
			//ru = 1;
		//switch (month)
		//{
			//case 1: dm = 0; days = 31; break;	
			//case 2: dm = 3; days = (ru == 1? 29:28); break; 	
			//case 3: dm = 3 + ru; days = 31; break;	
			//case 4:	dm = 6 + ru; days = 30; break;
			//case 5:	dm = 1 + ru; days = 31; break;
			//case 6: dm = 4 + ru; days = 30; break;	
			//case 7: dm = 6 + ru; days = 31; break;	
			//case 8: dm = 2 + ru; days = 31; break;	
			//case 9:	dm = 5 + ru; days = 30; break;	
			//case 10: dm = ru; days = 31; break;	
			//case 11: dm = 3 + ru; days = 30; break;	
			//case 12: dm = 5 + ru; days = 31; break;	
			//default:exit(1);
		//}
	//}
	//dmy[0] = dm + dy;
	//dmy[1] = days;
	//return dmy;
//}
