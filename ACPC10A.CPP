#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>


using namespace std;
int main()
{
	vector<vector<int> > A(10001, vector<int>(10001,-1));
	int i=0,j=0,temp=0;
	A[i][j] = 0;
	for (i = 1, j = 1;i < 10001;i++, j++)
	{
		if (temp % 2 == 0)
			A[i][j] = temp + 1;
		else
			A[i][j] = temp + 3;
		temp = A[i][j];
	}
	i = 2;j = 0;
	A[i][j] = 2;
	temp = A[i][j];
	for (i = 3, j = 1;i < 10001;i++, j++)
	{
		if (temp % 2 == 0)
			A[i][j] = temp + 1;
		else
			A[i][j] = temp + 3;
		temp = A[i][j];
	}
	int t;
	cin >> t;
	while (t--)
	{
		cin >> i>> j;
		if (A[i][j] != -1)
			cout << A[i][j] << endl;
		else
			cout << "No Number" << endl;
	}
	return 0;
}