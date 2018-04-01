/*
 * ANARC05B.cpp
 *
 *  Created on: 15-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size1,size2;
    cin>>size1;
    while(size1)
    {
    	vector<int> path1(size1);
    	for(int i = 0; i<size1;i++)
    		cin>>path1[i];
    	cin>>size2;
    	vector<int> path2(size2);
    	for(int i = 0;i<size2;i++)
    		cin>>path2[i];
    	vector<int> sum1(1);
    	vector<int> sum2(1);
    	int sum;
    	int k = 0;
    	for(int i = 0;i<size1;i++)
    	{
    		if(binary_search(ALL(path2),path1[i]))
    		{
    			sum1.push_back(0);
    			k++;
    		}
    		sum1[k] += path1[i];
    	}
    	k=0;
    	for(int i = 0;i<size2;i++)
    	{
       		if(binary_search(ALL(path1),path2[i]))
    	    {
    			sum2.push_back(0);
    	    	k++;
    	    }
       		sum2[k] += path2[i];
    	}
    	int result = 0;
    	int i;
    	int ssize1 = sum1.size();
    	int ssize2 = sum2.size();
    	for(i=0;i<min(ssize1,ssize2);i++)
    		result += max(sum1[i],sum2[i]);
    	int dub = i;
    	for(int j = dub;j<ssize1;j++)
    		result = max(result,sum1[j]);
    	for(int j = dub;j<ssize2;j++)
    		result = max(result,sum2[j]);
    	cout<<result<<endl;
    	cin>>size1;
    }
    return 0;
}


