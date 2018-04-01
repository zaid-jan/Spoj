/*
 * HPYNOS.cpp
 *
 *  Created on: 22-Aug-2017
 *      Author: zaidjan1295
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int split(int x, set<int>& disc, int& count)
{
	count++;
	int digit,num=0;
	while (x)
	{
		digit = x%10;
		digit = digit*digit;
		num += digit;
		x /= 10;
	}
	if(num == 1)
		return count;
	if(disc.find(num)==disc.end())
	{
		disc.insert(num);
		return split(num,disc,count);
	}
	if(disc.find(num)!=disc.end())
		return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int count = 0;
    	set<int> disc;
    	int x;
    	cin>>x;
    	disc.insert(x);
    	int result = split(x,disc,count);
    	cout<<result<<endl;
    }

    return 0;
}




 	
