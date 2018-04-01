/*
 * HACKRNDM.cpp
 *
 *  Created on: 08-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

vector<int> nums;

int bin(int low, int high, int num, int key)
{
	if(low>high)
		return 0;
	int mid = (low+high)/2;
	if(num - nums[mid] == abs(key))
		return 1;
	else if(num - nums[mid] < key)
		return bin(low,mid-1,num,key);
	else
		return bin(mid+1,high,num,key);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    nums.resize(n);
    for(int i = 0; i<n; i++)
    	cin>>nums[i];
    sort(ALL(nums));
    int count = 0;
    for(int i = 0;i < n; i++)
    	if(bin(0,n-1,nums[i],k))
    		count++;
    cout<<count<<endl;
    return 0;
}



