/*
 * CANTON.cpp
 *
 *  Created on: 02-Sep-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int even(int n)
{
	if(n%2==0)
		return 1;
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int term;
    	cin>>term;
    	int n = (-1 + sqrt(1 + 4*2*term))/2;
    	int at = (n*(n+1))/2;
    	n++;at++;
    	int diff = term - at;
    	if(1+diff!=0)
   		{
    		if(!even(n))
    			cout<<"TERM " << term <<" IS "<< n - diff << '/' << 1 + diff << endl;
    		else
    			cout<<"TERM " << term <<" IS "<<1 + diff << '/' << n - diff  << endl;
   		}
    	else
    	{
    		if(!even(n))
    			cout<<"TERM " << term <<" IS "<< n - 1 << '/' << 1 << endl;
    		else
    			cout<<"TERM " << term <<" IS "<< 1 << '/' << n - 1 << endl;
    	}
    }

    return 0;
}



