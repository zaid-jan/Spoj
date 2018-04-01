#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int u = 1;
	while (t--)
	{
		int amount;
		cin >> amount;
		int n;
		cin >> n;
		vector<int> A(n);
		for (int i = 0;i < n;i++)
			cin >> A[i];
		sort(A.begin(), A.end());
		cout << "Scenario #" << u << ":" << endl;
		int j=0;
		for (int i = A.size() - 1;amount > 0;i--)
		{
			amount -= A[i];
			j++;
			n--;
			if (n == 0)
				break;
		}
		if (n == 0)
			cout << "impossible"<<endl;
		else
			cout << j << endl;

		cout << endl;
		u++;
	}
}