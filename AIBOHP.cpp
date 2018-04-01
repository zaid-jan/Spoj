/*
 * AIBOHP.cpp
 *
 *  Created on: 23-Oct-2017
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
    	string orig,rev;
    	cin>>orig;
    	rev = orig;
    	reverse(ALL(rev));
    	int length = orig.length();
    	vector<vector<int> > dp(length+1, vector<int>(length+1));

    	for(int i = 1;i<=length;i++)
    		for(int j = 1;j<=length;j++)
    		{
    			if(orig[i-1] == rev[j-1])
    				dp[i][j] = dp[i-1][j-1] + 1;
    			else
    				dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
    		}
    	cout<<length - dp[length][length]<<endl;
    }
    return 0;
}



