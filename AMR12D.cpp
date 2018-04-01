/*
 * AMR12D.cpp
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	string orig;
    	cin>>orig;
    	string rev = orig;
    	reverse(rev.begin(),rev.end());
    	if(orig == rev)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }

    return 0;
}


