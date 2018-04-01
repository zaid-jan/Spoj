/*
 * DOTAA.cpp
 *
 *  Created on: 07-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int nheroes,ntowers, damage;
    	cin>>nheroes>>ntowers>>damage;
    	vector<int> hhealths(nheroes);
    	for(int i = 0;i<nheroes;i++)
    		cin>>hhealths[i];
    	sort(RALL(hhealths));
    	int i=0,changes = 0,towers = 0,heroes = 0;
    	while(i<hhealths.size())
    	{
    		if(hhealths[i] - damage > 0 && towers<ntowers)
    		{
    			hhealths[i] -= damage;
    			changes++;
    			towers++;
    			heroes++;
    		}
    		else
    			i++;;
    	}
    	if(changes == heroes && towers == ntowers)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    return 0;
}


