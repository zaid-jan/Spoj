/*
 * FAVDICE.cpp
 *
 *  Created on: 09-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
    	int n;
    	cin>>n;
    	double result = 0;
    	for(int i = 1; i <= n; i++)
    		result = result + double(1.0/i);
    	result *= n;
    	cout<<fixed<<setprecision(2)<<result<<'\n';
    }

    return 0;
}



