#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long result = 2*(n*(n+1))/2 + n*(n - 1) / 2;
		result = result % 1000007;
		cout << result << endl;
	}

	return 0;
}