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
		long long n;
		cin >> n;
		unsigned long long init = 192;
		init += 250 * (n - 1);
		cout << init << endl;
	}
	return 0;
}