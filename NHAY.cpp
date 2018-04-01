/*
 * NHAY.cpp
 *
 *  Created on: 16-Sep-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int n;

void make_nums(string needle,vector<int>& nums)
{
	int i=0,j=1;
	nums[i] = 0;
	while(needle[j]!='\0')
	{
		if(needle[i]==needle[j])
		{
			nums[j] = i+1;
			i++;j++;
		}
		else
		{
			if(!i)
			{
				nums[j] = 0;
				j++;
			}
			else
				i=nums[i-1];
		}
	}
}

vector<int> kmp(string hstack,string needle,vector<int> nums)
{
	int i=0,j=0,dub = -1;
	vector<int> results;
	while(hstack[i]!='\0')
	{
		i = dub + 1;
		dub = -1;
		bool found = 0;
		while(needle[j]!='\0' && hstack[i]!='\0')
		{
			if(hstack[i] == needle[j])
			{
				i++;j++;
				if(needle[j]=='\0')
					found = 1;
			}
			else if(hstack[i] != needle[j] && j==0)
				i++;
			else
				j=nums[j-1];
		}
		j=0;
		if(found)
			dub = i-n;
		if(dub != -1)
		results.push_back(dub);
	}
	return results;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(scanf("%d",&n)==1)
    {
    	string needle,hstack;
    	cin>>needle>>hstack;
    	vector<int> nums(n);
    	make_nums(needle,nums);
    	vector<int> results = kmp(hstack,needle,nums);
    	if(results.empty())
    		cout<<endl;
    	else
    		for(int i=0;i<results.size();i++)
    			cout<<results[i]<<endl;
    	cout<<endl;
    }

    return 0;
}
