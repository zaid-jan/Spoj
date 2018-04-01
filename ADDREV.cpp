#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int reverse(int a)
{
	int i;
	int orig,rev = 0,temp;
	orig = a;
	temp;
	while (a != 0)
	{
		temp = a % 10;
		a = a / 10;
		rev = rev * 10 + temp;
	}
	return rev;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int c = reverse(a);
		int d = reverse(b);
		cout << reverse(c + d) << endl;		
	}
}