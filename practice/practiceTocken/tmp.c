#include <stdio.h>
char ca[5] = "01234";
//void func(char ca[5])
//{
	//printf("%d\n", sizeof(ca));
	//printf("%d\n", &ca);
	//printf("%d\n", &(ca[0]));
	//printf("%d\n", &(ca[1]));
	//printf("%s\n", ++ca);
//}
//void func1(char *pa)
//{
	//printf("%d\n", sizeof(pa));
	//printf("%d\n", &pa);
	//printf("%d\n", &(pa[0]));
	//printf("%d\n", &(pa[1]));
	//printf("%s\n", ++pa);
//}
int main(int argc, char **argv)
{
	//func(ca);
	//printf("func1:\n");
	//func1(ca);
	//printf("main\n");
	//printf("%d\n", &ca);
	printf("%#x\n", &(ca[0]));
	printf("%#x\n", &(ca[0]));
	//printf("%d\n", &(ca[1]));
	//printf("%s\n", ca + 1);
	//printf("%d\n", sizeof(ca));
	//int apticot[2][3][4];
	//int (*r)[4] = apticot[0];
	//int *t = apticot[0][0]; 
	//int x, y, z;
	//for (x = 0; x < 2; x++)
		//for (y = 0; y < 3; y++)
			//for (z = 0; z < 4; z++)
				//printf("%x  x = %d y = %d z = %d\n", &apticot[x][y][z], x, y, z);
	//printf("(*r) [4] is %x\n", r);
	//printf("*t is %x\n", t + 1);
	//float b[2];
	//int a[2];
	//printf("%#x  %#x\n", b[0], a[0]);
	return 0;
}
