#include <ncurses.h>

int main (int argc, char **argv)
{
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	printw("A Big string which i didn't care to type fully");
	mvchgat(10, 10, -1, A_BOLD, 1, NULL);
	refresh();
	getch();
	endwin();
	return 0;
}
