#include <stdio.h>

float ave(float sum, int n)
{
	float aver = sum/(n);
	printf("The average is %.3f\nsum = %f\nn = %d\n", aver, sum, n);
	return aver;
}
int main (int argc, char **argv)
{
	float x[10], sum = 0.0, a, aver;
	int n = 0, i;
	printf("Enter mark :\n");
	scanf("%f", &a);
	while (a > 0.0 && n < 10)
	{
		sum += a;	
		x[n] = a;
		++n;
		scanf("%f", &a);
	}
	aver = ave(sum, n);
	for (i = 0; i < n; ++i)
		if (x[i] < aver)
			printf("%4.3f\n", x[i]);
	return 0;
}
