#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int prime(int x)
{
	int i;
	bool p = 1;
	for (i = 2;i < x;i++)
		if (x%i != 0)
			p = 1;
		else
		{
			p = 0;
			break;
		}
			
	if (p == 0)
		return 0;
	else 
		return 1;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (x == 1)
			x++;
		int i;
		vector<int> A;
		vector<int> B;
		for (i = x;i <= y;i++)
			A.push_back(i);
		for (i = 0;i < A.size();i++)
			if (prime(A[i]))
				B.push_back(A[i]);
		for (i = 0;i < B.size();i++)
			cout << B[i] << endl;

	}
	return 0;
}