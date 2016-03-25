#include <stdio.h>

void my_fucntion_1(int fruit[2][3][4]){;}
void my_fucntion_2(int fruit[][3][4]){;}
void my_fucntion_3(int (*fruit)[3][4]){;}

int main(int argc, char **argv)
{
	//char a[4][4] = {
						//{'b','a','b','b'},	
						//{'b','c','b','b'},	
						//{'b','b','b','b'},	
						//{'b','b','b','b'}	
				   //};
	//char *b[4] = {"abcd","qwer","qwer","qwer"};
	//char (*c)[4] = a; 
	//char **d = b; 
	//printf("a[4][4] %c\n", a[0][0]);
	//printf("*b[4] %c\n", *b[0]);
	//printf("(*c)[4] %c\n", *((*c) + 1));
	//printf("**d %s\n", *(d + 1) + 1);
	//char a[3][4] = {
					//"aaaa",
					//"bbbb",
					//"cccc"
				  //};
	//char b[3][4] = {
					//"aaaa",
					//"bbbb",
					//"cccc"
				  //};
//
	int apricot[2][3][4] = {
								{
									{'a','b','c','d'},
									{'a','b','c','d'},
									{'a','b','c','d'}
								},
								{
									{'a','b','c','d'},
									{'a','b','c','d'},
									{'a','b','c','d'}
								}
							};
	//my_fucntion_1(apricot);
	//my_fucntion_2(apricot);
	//my_fucntion_3(apricot);
	//int (*p)[3][4] = apricot;
	//my_fucntion_1(p);
	//my_fucntion_2(p);
	//my_fucntion_3(p);
	//int (*q)[2][3][4] = &apricot;
	//my_fucntion_1(*q);
	//my_fucntion_2(*q);
	//my_fucntion_3(*q);
	char *p = NULL;
	printf("%s", p);
	return 0;
}
