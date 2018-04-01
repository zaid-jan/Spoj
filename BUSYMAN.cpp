/*
 * BUSYMAN.cpp
 *
 *  Created on: 04-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.second < b.second)
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
    	int n;
    	cin>>n;
    	vector<pair<int,int> > pairs(n);
    	for(int i=0;i<n;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		pairs[i].first = x;
    		pairs[i].second = y;
    	}
    	int count=0;
    	sort(pairs.begin(),pairs.end(),sortbysec);
    	count++;
    	int j = 0;
    	for(int i=1;i<n;i++)
    	{
    		if(pairs[i].first >= pairs[j].second)
    		{
    			count++;
    			j = i;
    		}
    	}
    	cout<<count<<endl;
    }

    return 0;
}

