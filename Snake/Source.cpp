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
bool checkIfSnakeEatsFood(Snake & snake, Food & food)
{
	if (snake.body[0].x == food.body.x && snake.body[0].y == food.body.y)
	{
		return true;
	}
	else { return false; }
}
void snakeEat(Snake & snake, Food & food) {
	snake.body[snake.length].x = food.body.x;
	snake.body[snake.length].y = food.body.y;
	++snake.length;
}
void generateFood(Snake & snake, Food & food)
{
	food.body.x = rand() % 20 + 5;
	food.body.y = rand() % 20 + 5;
	for (int i = 0; i < snake.length; ++i)
	{
		if (food.body.x == snake.body[i].x && food.body.y == snake.body[i].y) 
		{
			generateFood(snake, food);
		}
	}
}
void game()
{
	Snake snake;
	Food food;
	generation(snake, food);
	while (true)
	{
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
		if (checkIfSnakeEatsFood(snake, food))
		{
			snakeEat(snake, food);
			generateFood(snake, food);
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