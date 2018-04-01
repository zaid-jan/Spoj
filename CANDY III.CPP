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
	while (t--)
	{
		cout << endl;
		int n;
		cin >> n;
		vector<unsigned long long> a(n);
				
		for (int i = 0;i < n;i++)
			cin >> a[i];
		unsigned long long sum=0;
		for (int i = 0;i < n;i++)
		{
			sum = (sum+a[i]) % n;
		}
		if (!sum)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}