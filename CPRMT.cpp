/*
 * CPRMT.cpp
 *
 *  Created on: 08-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()


int main()
{
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    while(cin>>a)
    {
    	vector<char> result;
    	string b;
    	cin>>b;
    	vector<int> hashmap(26,0);
    	for(unsigned int i = 0; i<a.length(); i++)
    	{
    		if(!hashmap[a[i]-'a'])
    			hashmap[a[i]-'a'] = 1;
    		else
    			hashmap[a[i]-'a']++;
    	}
    	for (unsigned int i = 0; i<b.length(); i++)
    	{
    		if(hashmap[b[i]-'a']!=0)
    		{
    			result.push_back(b[i]);
    			hashmap[b[i]-'a']--;
    		}
    	}
    	sort(ALL(result));
    	for(auto it = result.begin(); it != result.end(); it++)
    		cout<< *it;
    	cout<<'\n';
    }


    return 0;
}



