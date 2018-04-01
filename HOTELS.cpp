/*
 * HOTELS.cpp
 *
 *  Created on: 24-Aug-2017
 *      Author: zaidjan1295
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

#define ll long long;
#define MOD 1000000007;

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> hotels(n);
    for(int i=0;i<n;i++)
    	cin>>hotels[i];

    int low=0,high = 0;
    int result = INT_MIN,sum=0;

    while(low<=high && high < n)
    {
    	if(sum==m)
    	{
    		result = m;
    		break;
    	}
    	else if(sum+hotels[high]>=m)
   	   	{
   	    	sum -= hotels[low];
   	    	low++;
   	    	continue;
     	}
    	else if(sum<m)
    	{
    		sum += hotels[high];
    		high++;
    	}
    	if(result<=sum && sum <=m)
    		result = sum;

    }
    cout<<result<<endl;


    return 0;
}

