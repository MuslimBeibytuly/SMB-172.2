#include <iostream>

int findMost(int *a, int n) {
	return 0;
}
int main() 
{
	int n;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i) 
	{
		a[i] = rand() % 100;
	}
	std::cout << findMost(a, n);
	delete[] a;
	system("pause");
	return 0;
}