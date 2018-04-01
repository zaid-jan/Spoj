/*
 * COINS.cpp
 *
 *  Created on: 24-Sep-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define MAX

long long max(long long a,long long b)
{
	if(a>b)
		return a;
	else
		return b;
}

long long find_result(long long n, map<long long, long long>& dp)
{
	if(n<=0)
		return 0;
	if(dp.count(n)==0)
	{
		long long b2 = max(n/2,find_result(n/2,dp));
		long long b3 = max(n/3,find_result(n/3,dp));
		long long b4 = max(n/4,find_result(n/4,dp));
		dp[n] = max(n,b2+b3+b4);
	}
	return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    map <long long,long long> dp;
    while(cin>>n)
    {
    	long long result = find_result(n,dp);
    	cout<<result<<endl;
    }
    return 0;
}


