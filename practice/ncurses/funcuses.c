#include <ncurses.h>

int main (int argc, char **argv)
{
	int ch;

	initscr();
	raw();/*close the line buffer*/
	keypad(stdscr, TRUE);/*open the keypad*/
	noecho();
	printw("Type any character to see it in bold\n");
	ch = getch();
	if (ch == KEY_F(1))
		printw("F1 Key pressed");
	else 
	{
		printw("The pressed key is:");	
		//attron(A_BLOD);
		printw("%c", ch);
		//attroff(A_BLOD);
	}
	refresh();
	getch();
	endwin();
	return 0;
}
