/*
 * EDIST.cpp
 *
 *  Created on: 05-Sep-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	string a,b;
    	cin>>a>>b;;
    	int alen = a.length();
    	int blen = b.length();
    	vector<vector<int> > dp(alen+1,vector<int> (blen + 1));
    	dp[0][0] = 0;
    	for(int i = 1; i <= alen; i++)
    		dp[i][0] = i;
    	for(int i = 1; i <= blen; i++)
    	    dp[0][i] = i;

    	for(int i = 1; i <= alen; i++)
    	{
    		for(int j = 1;j <= blen; j++)
    		{
    			if(a[i - 1] == b[j - 1])
    				dp[i][j] = dp[i - 1][j - 1];
    			else
    				dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
    		}
    	}
    	int result = dp[alen][blen];
    	cout<<result<<endl;
    }


    return 0;
}


