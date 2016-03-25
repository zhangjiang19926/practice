#include <ncurses.h>

int main (int argc, char **argv)
{
	int ch, prev;
	FILE *fp;
	int goto_prev = FALSE, y, x;
	if (argc != 2)
	{
		printf("Usage : %s < a c file name >\n", *argv);	
		exit(1);
	}
	fp = fopen(*(argv + 1), "r");/*argv xiang dang yu er wei shuzu*/
	if (fp == NULL)
	{
		perror("Cannot open input file");	
		exit(1);
	}
	initscr();
	prev = EOF;
	while ((ch = fgetc(fp)) != EOF)/*sjjjjjjjjjjjjL:*/
	{
		if (prev == '/' && ch == '*')	
		{
			attron(A_BOLD | A_UNDERLINE | A_BLINK);	
			goto_prev = TRUE;
		}
		if (goto_prev == TRUE)
		{
			getyx(stdscr, y, x);	
			move(y, x-1);/*lllllllllllllllllllllllll:*/
			printw("%c%c", '/', ch);
			ch = 'a';
			goto_prev = FALSE;/*fafdafdsaf*/
		}
		else printw("%c", ch);/*jssssdssadadsa:*/
		refresh();
		if (prev == '*' && ch == '/')/*fjakjfdafafdsafsdafdsa*/
			attroff(A_BOLD | A_UNDERLINE | A_BLINK);
		prev = ch;
	}
	getch();
	endwin();/*fjfkdjsafaffafdasfasdfasfasf;*/
	return 0;
}
