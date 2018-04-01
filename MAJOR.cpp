/*
 * MAJOR.cpp
 *
 *  Created on: 22-Oct-2017
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
    	int n;
    	cin>>n;
    	if(n==0)
    	{
    		cout<<"NO"<<'\n';
    		continue;
    	}
    	unordered_map<int,int> sig;
    	for(int i = 0; i < n;i++)
    	{
    		int x;
    		cin>>x;
    		if(sig.find(x) == sig.end())
    			sig.insert(make_pair(x,1));
    		else
    			sig[x]++;
    	}
    	unordered_map<int,int>::iterator it;
    	bool found = false;
    	for(it = sig.begin(); it != sig.end(); it++)
    	{
    		if(it->second > n/2)
    		{
    			cout<<"YES"<<' '<<it->first<<endl;
    			found = true;
    			break;
    		}
    	}
    	if(!found)
    		cout<<"NO"<<endl;
    }
    return 0;
}


