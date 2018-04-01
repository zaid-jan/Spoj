#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		long long num;
		cin >> num;
		int x;
		cin >> x;
		if (x)
			cout << "Pagfloyd wins." << endl;
		else
			cout << "Airborne wins." << endl;
	}

	return 0;
}