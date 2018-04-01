/*
 * PRIME1.cpp
 *
 *  Created on: 15-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

bool is_prime(unsigned long long x)
{
	if(x==1)
		return 0;
	for(unsigned long long i = 2; i <= sqrt(x); i++)
		if(x%i == 0)
			return 0;
	return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	unsigned long long range1,range2;
    	cin>>range1>>range2;
    	for(unsigned long long i = range1;i <= range2; i++)
    		if(is_prime(i))
    			cout<<i<<endl;
    }

    return 0;
}


