#include "Mammal.h"

int main() 
{
	Mammal a;
	a.setAmountOfEyes(-1);
	a.setAmountOfEyes(2);
	std::cout << a.getAmountOfEyes() << std::endl;
	system("pause");
	return 0;
}
