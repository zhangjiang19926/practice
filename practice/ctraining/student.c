#include <stdio.h>
#include <string.h>

void Sort(float *grade, int length)
{
	float tmp;
	int i, j;
	for (i = 0; i < length; ++i)
	{
		for (j = i + 1; j < length; ++j)
			if (grade[i] < grade[j])	
			{
				tmp = grade[i];		
				grade[i] = grade[j];
				grade[j] = tmp;
			}
	}
}
void Input(float *grade, int length)
{
	int i;
	for (i = 0; i < length; ++i) 
		scanf("%f", grade + i);
}

void Output(float *grade, int length)
{
	int i;
	for (i = 0; i < length; ++i)
		printf("%d's grade is %f\n", i, *(grade + i));
}

void Insert(float *grade, int length)
{
	
}

int main(int argc, char **argv)
{
	float grade[11];	
	Input(grade, 11);
	Sort(grade, 11);
	Output(grade, 11);
	return 0;
}
