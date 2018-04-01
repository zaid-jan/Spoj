/*
 * TWOSQRS.cpp
 *
 *  Created on: 20-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define ull unsigned long long


int bin(ull low, ull high, ull x, ull final)
{
	if(low>high)
		return 0;
	ull mid = (low+high)/2;
	ull result = x*x + mid*mid;
	if(result == final)
		return 1;
	else if(result > final)
		return bin(low,mid-1,x,final);
	else
		return bin(mid+1,high,x,final);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	ull n;
    	cin>>n;
    	ull result = INT32_MAX;
    	bool found = 0;
    	for(ull i = 0; i <= sqrt(n); i++)
    		if(bin(0,sqrt(n),i,n))
    		{
    			found = 1;
    			break;
    		}
    	if(found)
    		cout<<"Yes"<<endl;
    	else
    		cout<<"No"<<endl;
    }
    return 0;
}



