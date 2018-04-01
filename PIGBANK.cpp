/*
 * PIGBANK.cpp
 *
 *  Created on: 08-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define MAX 1000000

vector<int> val;
vector<int> wt;
vector<int> table;
int n;

int dp(int effwt)
{
	if(effwt <0 )
		return MAX;
	if(table[effwt] == -1)
	{
		int curval;
		int temp = MAX;
		if(effwt == 0)
			table[effwt] = 0;
		else
		{
			for(int j = 0;j<n;j++)
			{
				if(effwt - wt[j] >= 0)
				{
					curval = val[j] + dp(effwt - wt[j]);
					temp = min(temp,curval);
				}
			}
			table[effwt] = temp;
		}
	}
	return table[effwt];
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int emptyw, fullw;
    	cin>>emptyw>>fullw>>n;
    	val.resize(n);
    	wt.resize(n);
    	int effwt = fullw-emptyw;
    	table.resize(effwt+1,-1);
    	for(int i = 0;i<n;i++)
    		cin>>val[i]>>wt[i];
    	int result = dp(effwt);
    	if(result == MAX)
    		cout<<"This is impossible."<<endl;
    	else
    		cout<<"The minimum amount of money in the piggy-bank is "<<result<<'.'<<endl;
    	val.clear();
    	wt.clear();
    	table.clear();
    }
}


