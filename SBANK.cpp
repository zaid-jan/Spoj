/*
 * SBANK.cpp
 *
 *  Created on: 21-Sep-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int nacc;
    	cin>>nacc;
    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    	map<string,int> accounts;
       	while(nacc--)
    	{
    		string temp;
    		getline(cin,temp);
    		if(accounts.find(temp)!=accounts.end())
    			accounts[temp] += 1;
    		else
    			accounts.insert(pair<string,int>(temp,1));
        }
    	for(map<string,int>::iterator it = accounts.begin();it!=accounts.end();it++)
    		cout<<it->first<<' '<<it->second<<endl;
    	cout<<endl;
    }
    return 0;
}


