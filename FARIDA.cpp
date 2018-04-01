/*
 * FARIDA.cpp
 *
 *  Created on: 24-Sep-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

long long monsters(int i, vector<long long>& orig, vector<long long>& dp)
{
	if(i<0)
		return 0;
	long long sum1=orig[i], sum2=orig[i];
	if(dp[i] == -1)
	{
		sum1 += monsters(i-2, orig, dp);
		sum2 += monsters(i-3, orig, dp);
		dp[i] = max(sum1,sum2);
	}
	return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    int t;
    cin>>t;
    while(t--)
    {
    	count++;
    	int size;
    	cin>>size;
    	if(!size)
    	{
    		cout<<"Case "<<count<<": "<<0<<endl;
    		continue;
    	}
    	vector<long long> orig(size),dp(size, -1);
    	for(int i=0;i<size;i++)
    		cin>>orig[i];
    	long long result1 = monsters(size-1,orig,dp);
    	long long result2 = monsters(size-2,orig,dp);
    	cout<<"Case "<<count<<": "<<max(result1,result2)<<endl;
    }

    return 0;
}


