#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Point
{
	short x, y;
};
struct Snake
{
	Point * body;
	int length;
	char sign = '*';
};
struct Food
{
	Point body;
	char sign = '#';
};
void draw(Point & p, char sign) 
{
	COORD position = { p.x, p.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << sign;
}
void drawEverything(Snake & snake, Food & food) 
{
	for (int i = 0; i < snake.length; ++i) {
		draw(snake.body[i], snake.sign);
	}
	draw(food.body, food.sign);
}
void generation(Snake & snake, Food & food) 
{
	snake.body = new Point[20];
	snake.body[0].x = 3;
	snake.body[0].y = 3;
	snake.length = 1;
	food.body.x = 5;
	food.body.y = 5;
}
void snakeMove(Snake & snake, int dx, int dy) 
{
	//остальные подтягиваются
	for (int i = snake.length; i > 0; --i) {
		snake.body[i].x = snake.body[i - 1].x;
		snake.body[i].y = snake.body[i - 1].y;
	}
	//нулевой элемент - голова
	snake.body[0].x += dx;
	snake.body[0].y += dy;
}

void game()
{
	Snake snake;
	Food food;
	generation(snake, food);
	while (true) {
		drawEverything(snake, food);
		char action = _getch();
		switch (action)
		{
		case 'a':
			snakeMove(snake, -1, 0);
			break;
		case 'w':
			snakeMove(snake, 0, -1);
			break;
		case 's':
			snakeMove(snake, 0, 1);
			break;
		case 'd':
			snakeMove(snake, 1, 0);
			break;
		case 'q':
			return;
		default:
			break;
		}
		system("cls");
	}
	delete[] snake.body;
}

int main()
{
	game();
	return 0;
}