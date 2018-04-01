/*
 * COMDIV.cpp
 *
 *  Created on: 30-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int count = 0;
    	int x,y;
    	cin>>x>>y;
    	int gcd = __gcd(x,y);
    	for(int i = 1; i<=gcd; i++)
    		if(gcd%i == 0)
    			count++;
    	cout<<count<<'\n';
    }

    return 0;
}



