/*
 * OLOLO.cpp
 *
 *  Created on: 04-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int result = 0;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
    {
    	cin>>nums[i];
    	result ^= nums[i];
    }
    cout<<result<<endl;
    return 0;
}
