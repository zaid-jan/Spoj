/*
 * FCTRL.cpp
 *
 *  Created on: 25-Sep-2017
 *      Author: zaidjan1295
 */

#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n;
		int fives = 5;
		long long sum = 0;
		while(fives <= n)
		{
			sum += n/fives;
			fives *= 5;
		}
		cout<<sum<<endl;
	}
}


