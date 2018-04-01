#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int column;
	cin >> column;
	while (column)
	{
		string a;
		cin >> a;
		int row = a.length() / column;
		vector<vector<char> > A(row, vector<char>(column));
		int count = 0;
		int x = 0, y = 1, k = 0;
		while (count != a.length())
		{
			for (int i = x;i < y;i++)
				for (int j = 0;j < column;j++)
				{
					A[i][j] = a[k];
					count++;
					k++;
				}
			x++;y++;
			if (count == a.length())
				break;
			for (int i = x;i<y;i++)
				for (int j = column - 1;j >= 0;j--)
				{
					A[i][j] = a[k];
					count++;
					k++;
				}
			x++;y++;
		}
		for (int i = 0;i < column;i++)
			for (int j = 0;j < row;j++)
				cout << A[j][i];
		cout << endl;
		cin >> column;
	}
	return 0;
}