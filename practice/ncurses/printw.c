#include <ncurses.h>
#include <string.h>

int main (int argc, char **argv)
{
	char mesg[] = "Just a string";
	int row, col;
	initscr();
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col - strlen(mesg))/2, "%s", mesg);
	mvprintw(row/2- 10, (col - strlen(mesg))/2 - 10, "%s", "hello world!!");
	mvprintw(row-2, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing your window(if possible) and then run this program again\n");
	refresh();
	getch();
	endwin();
	return 0;
}
