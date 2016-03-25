#include <ncurses.h>
#include <string.h>
#include <stdio.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int main (int argc, char **argv)
{
	initscr();
	if (has_colors() == FALSE)
	{
		endwin();	
		printf("You terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, LINES / 2, 0, 0, "Hello world!");
	attroff(COLOR_PAIR(1));
	getch();
	endwin();
	return 0;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{
	int length, x, y;
	float tmp;
	if (win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if (startx != 0)
		x = startx;	
	if (starty != 0)
		y = starty;
	if (width == 0)
		width = 80;
	length = strlen(string);
	tmp = (width - length) / 2;
	x = startx + (int)tmp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
