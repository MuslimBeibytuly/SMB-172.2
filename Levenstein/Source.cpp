#include <string>
#include <iostream>

using namespace std;
int min(int, int);
int findLevensteinDistance(string s1, string s2)
{
	int ** d = new int *[s1.length()];
	for (int i = 0; i < s1.length(); ++i)
	{
		d[i] = new int[s2.length()];
	}
	//algorithm itself
	d[0][0] = 0;
	for (int i = 1; i < s1.length(); ++i)
	{
		d[i][0] = i;
	}
	for (int j = 1; j < s2.length(); ++j)
	{
		d[0][j] = j;
	}
	for (int i = 1; i < s1.length(); ++i)
	{
		for (int j = 1; j < s2.length(); ++j)
		{
			int temp1 = min(d[i][j - 1] + 1, d[i - 1][j] + 1);
			int temp2;
			if (s1[i] == s2[j]) 
			{
				temp2 = d[i - 1][j - 1];
			}
			else {
				temp2 = d[i - 1][j - 1] + 1;
			}
			d[i][j] = min(temp1, temp2);
		}
	}
	int distance = d[s1.length() - 1][s2.length() - 1];
	for (int i = 0; i < s1.length(); ++i)
	{
		delete[] d[i];
	}
	delete[] d;
	return distance;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << findLevensteinDistance(s1, s2);
	system("pause");
	return 0;
}
int min(int a, int b)
{
	return ((a / b) * b + (b / a) * a) / (a / b + b / a);
}