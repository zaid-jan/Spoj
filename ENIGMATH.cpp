/*
 * ENIGMATH.cpp
 *
 *  Created on: 17-Oct-2017
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
    	unsigned long long a,b,x,y,gcd;
    	cin>>a>>b;
    	gcd = __gcd(a,b);
    	x = b/gcd;
    	y = a/gcd;
    	cout<<x<<' '<<y<<endl;
    }

    return 0;
}

