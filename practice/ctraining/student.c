#include <stdio.h>
#include <string.h>

void Sort(float *grade, int length)/*利用冒泡进行排序的函数*/
{
	float tmp;
	int i, j;
	for (i = 0; i < length - 1; ++i)
	{
		for (j = i + 1; j < length - 1; ++j)
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
	for (i = 0; i < length - 1; ++i) 
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

void Insert(float *grade, float grade_Insert, int length)
{
	float tmp;
	int i, j, num_tmp, flag;
	*(grade + length - 1) = 0;
	for (i = 0; i < length - 1; ++i)
	{
		if (*(grade + i) <= grade_Insert)
		{
			num_tmp = i;
			for (i = length - 1; i >= length - num_tmp; --i)
				*(grade + i) = *(grade + i - 1); 
			*(grade + num_tmp) = grade_Insert;
			flag = 0;
			break;
		}
		else 
			flag = 1;
	}
	if (flag == 1)
		*(grade + length - 1) = grade_Insert;
	//for (i = 0; i < length; ++i)
	//{
		//for (j = i + 1; j < length; ++j)
			//if (grade[i] > grade[j])	
			//{
				//tmp = grade[i];		
				//grade[i] = grade[j];
				//grade[j] = tmp;
			//}
	//}
}

int main(int argc, char **argv)
{
	int stuNum[5];
	float grade[5];	
	char stuName[5][10];
	Input(stuName, stuNum, grade, 5);
	Sort(grade, 5);
	Insert(grade, 12, 5);
	Output(stuName, grade, 5);
	return 0;
}
