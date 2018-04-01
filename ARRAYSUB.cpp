/*
 * ARRAYSUB.cpp
 *
 *  Created on: 07-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

int find_new(vector<int> nums, int i, int k)
{
	int currmax = -1;
	for(int i = 0;i<k;i++)
	    if(nums[i] > currmax)
	   		currmax = nums[i];
	return currmax;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    	cin>>nums[i];
    int k;
    cin>>k;
    multiset<int> mset;
    for(int i = 0;i<k;i++)
    	mset.insert(nums[i]);
    auto it1 = mset.end();
    it1--;
    cout<<*it1<<' ';
    for(int i=0;i+k<n;i++)
    {
    	mset.insert(nums[i+k]);
    	auto it = mset.lower_bound(nums[i]);
    	mset.erase(it);
    	auto end = mset.end();
    	end--;
    	cout<<*end<<' ';
    }
    cout<<endl;
    return 0;
}



