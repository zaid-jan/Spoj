/*
 * asdsad.cpp
 *
 *  Created on: 20-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

int bin(vector<int>& mount, int low, int high, int x)
{
	if(low>high)
		return INT32_MAX;
	int mid = (low+high)/2;
	int result = x - mount[mid];
	if(result == 0)
		return result;
	else if(result > 0)
		return min(abs(result), bin(mount, mid + 1, high, x));
	else
		return(min(abs(result), bin(mount, low, mid - 1, x)));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int size1,size2;
    	cin>>size1;
    	vector<int> mount1(size1);
    	for(int i = 0;i < size1; i++)
    		cin>>mount1[i];
    	cin>>size2;
    	vector<int> mount2(size2);
    	for(int i = 0;i < size2; i++)
    		cin>>mount2[i];
    	sort(ALL(mount2));
    	int result = INT32_MAX;
    	for(int i = 0; i < size1; i++)
    		result = min(result, bin(mount2, 0, size2 - 1, mount1[i]));
    	cout<<result<<endl;
    }

    return 0;
}



