#include <ncurses.h>
#include <string.h>

int main (int argc, char **argv)
{
	char mesg[] = "Enter a string";
	char str[80];
	int row, col;
	initscr();
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col - strlen(mesg)) / 2, "%s:", mesg);
	//getstr(str);
	scanw("%s", str);
	//mvscanw(row, col, "%s", str);
	mvprintw(LINES - 2, 0, "You Entered: %s", str);
	getch();
	endwin();
	return 0;
}
