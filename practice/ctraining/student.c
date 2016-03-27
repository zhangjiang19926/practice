#include <stdio.h>
#include <string.h>

void Sort(float *grade, int length)/*利用冒泡进行排序的函数*/
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
void Input(char stuName[][10], int *stuNum, float *grade, int length)/*输入成绩和学生姓名*/
{
	int i, j, flag = 1;
	char c;
	for (i = 0; i < length; ++i) 
	{
		printf("Please input %d student's information\n", i + 1);
		printf("%d's studentname = ", i + 1);/*输入名字*/
		scanf("%s", stuName[i]);/*以字符串的节奏输入到数组中*/
		flag = 1;
		printf("\n");
		printf("%d's studentnumber = ", i + 1);/*输入学生学号*/
		scanf("%d", stuNum + i);

		printf("\n");
		printf("%d student's grade = ", i + 1);/*输入学生成绩*/
		scanf("%f", grade + i);
		printf("\n");
		c = getchar();
	}
}

void Output(char stuName[][10], float *grade, int length)/*输出成绩及姓名*/
{
	int i, j, flag = 1;
	for (i = 0; i < length; ++i)
	{
		printf("%s's grade", *(stuName + i));
		printf("%d's grade is %f\n", i + 1, *(grade + i));
	}
}

void Insert(float *grade, int length)
{
	
}

int main(int argc, char **argv)
{
	int stuNum[2];
	float grade[2];	
	char stuName[2][10];
	Input(stuName, stuNum, grade, 2);
	Sort(grade, 2);
	Output(stuName, grade, 2);
	return 0;
}
