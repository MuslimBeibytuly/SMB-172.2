#include <iostream>
#include <vector>
using namespace std;

struct index
{
	int i;
	int j;
};

int main() {
	int n, m;
	cin >> n >> m;
	int ** a = new int *[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<index> col;
	for (int j = 0; j < m; ++j) {
		int max = a[0][j];
		index max_i = { 0, j };
		for (int i = 0; i < n; ++i) {
			if (a[i][j] > max) {
				max = a[i][j];
				max_i = { i, j };
			}
		}
		col.push_back(max_i);
	}
	vector<index> row;
	for (int i = 0; i < n; ++i) {
		int min = a[i][0];
		index min_i = { i, 0 };
		for (int j = 0; j < m; ++j) {
			if (a[i][j] < min) {
				min = a[i][j];
				min_i = { i, j };
			}
		}
		row.push_back(min_i);
	}
	vector<index> res;
	for (int x = 0; x < col.size(); ++x)
	{
		for (int y = 0; y < row.size(); ++y)
		{
			if (col[x].i == row[y].i && col[x].j == row[y].j)
			{
				res.push_back({ col[x].i + 1, col[x].j + 1 });
			}
		}
	}
	if (res.empty()) {
		cout << 0;
	}
	else {
		for (int x = 0; x < res.size(); ++x) {
			cout << res[x].i << ' ' << res[x].j << endl;
		}
	}

	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
	system("pause");
	return 0;
}