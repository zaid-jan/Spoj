/*
 * ABCDEF.cpp
 *
 *  Created on: 30-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

/*void rz()
{
	matrix.resize(rows);
	for(int i = 0; i<rows; i++)
		matrix[i].resize(columns);
}

void cle()
{
	for(int i = 0; i < rows; i++)
		matrix[i].clear();
	matrix.clear();
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    	cin>>nums[i];
    unordered_map<int,int> ltable;
    int result;
    vector<int> a;
    for(int i = 0; i<n; i++)
    	for(int j = 0; j<n; j++)
    		for(int k = 0;k<n; k++)
    		{
    			a.push_back(nums[i]*nums[j]+nums[k]);
    		}
    for(int i = 0; i<n; i++)
    	for(int j = 0; j<n; j++)
    		for(int k = 0; k<n ;k++)
    		{
    			int d = nums[i];
    			int e = nums[j];
    			int f = nums[k];
    			if(d == 0)
    				break;
    			result = d*(e+f);
    			if(ltable.count(result) > 0)
    				 ltable[result]++;
    			else
    				ltable[result] = 1;
    		}
    int answer = 0;
    for(int i = 0; i<a.size();i++)
    	if(ltable.count(a[i])>0)
    		answer += ltable[a[i]];
    cout<<answer<<endl;
    return 0;
}



