#include <iostream>
#pragma once

class Mammal
{
private:
	//state
	int amountOfEyes;
	char *name, *color, *form;
public:
	//getters and setters
	int getAmountOfEyes();
	void setAmountOfEyes(int _amountOfEyes);
	//operations
	void eat();
public:
	Mammal();
	~Mammal();
};
