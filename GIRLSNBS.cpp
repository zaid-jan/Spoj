#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	while (x != -1 && y != -1)
	{
		int total = x + y;
		int min_num = min(x, y);
		double result = ceil((total / (min_num + 1)));
		cout << result << endl;
		cin >> x >> y;
	}
	return 0;
}