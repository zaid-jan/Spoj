/*
 * AMR10G.cpp
 *
 *  Created on: 23-Aug-2017
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

    int t;
    cin>>t;
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;
    	vector<int> kids(n);
    	for(int i=0;i<n;i++)
    		cin>>kids[i];
    	sort(kids.rbegin(),kids.rend());
    	int diff = INT_MAX;
    	for(int i=0;i<=n-k;i++)
    		if(diff>kids[i]-kids[i+k-1])
    			diff = kids[i]-kids[i+k - 1];
    	cout<<diff<<endl;
    }

    return 0;
}
