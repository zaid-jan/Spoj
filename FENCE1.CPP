#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define PI 3.14159

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double l;
	cin >> l;
	while (l)
	{

		double radius = l / (PI);
		double area = (PI*radius*radius) / 2;
		printf("%.2lf\n", area);
		cin >> l;
	}
	return 0;
}