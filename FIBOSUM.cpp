/*
 * FIBOSUM.cpp
 *
 *  Created on: 30-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

#define MOD 1000000007

map<int,long long> m;

long long fib(int n)
{
	if(m.count(n) == 0)
	{
		int halved = ( n % 2 == 0 ) ? n / 2 : ( n / 2 ) + 1;

		long long p1 = fib(halved)%MOD;
		long long p2 = fib(halved - 1)%MOD;

		if(n%2==0)
		{
			long long x = (((2*p2+p1)%MOD)*(p1%MOD))%MOD; ;
			m.insert(make_pair(n,x)) ;
		}
		else
		{
			long long y = (p2*p2 % MOD + p1*p1 % MOD)%MOD;
			m.insert(make_pair(n,y));
		}
	}
	return m[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int x,y;
    	cin>>x>>y;
    	m[0] = 0;
    	m[1] = 1;
    	long long sum1 = fib(y+2)-1;
    	long long sum2 = fib(x+1)-1;
    	long long result = sum1-sum2;
    	if(result<0)
    		result += MOD;
    	cout<<result<<'\n';
    }
    return 0;
}



