#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long a3, l3, s;
		cin >> a3 >> l3 >> s;
		unsigned long long m = (2 * s) / (a3 + l3);
		unsigned long long d = -(a3 - l3) / (m-5);		 
		unsigned long long a1 = a3 - 2 * d;
		cout << m << endl;
		for (int i = 1;i <= m;i++)
			cout << a1 + (i - 1)*d << " ";
		cout << endl;
	}	
	return 0;
}