#include <Windows.h>
#include "Tic_Tac_Toe/HeaderFiles/gp1colourconsole.h"

void set_text_colour(int foreground, int background)
{
	HANDLE console_window = GetStdHandle(STD_OUTPUT_HANDLE);
	int colour = ((background & 0x0F) << 4) | (foreground & 0x0F);
	SetConsoleTextAttribute(console_window, colour);
}

void move_cursor_to(int column, int row)
{
	HANDLE console_window = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = column;
	position.Y = row;
	SetConsoleCursorPosition(console_window, position);
}