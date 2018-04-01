#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	float a;
	cin >> a;
	while (a)
	{
		float result = 0;
		int j=0;
		for (int i = 2;result < a;i++)
		{
			result += 1.00 / (i);
			j++;
		}
		cout << j << " card(s)" << endl;
		cin >> a;
	}
}