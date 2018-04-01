/*
 * PARTY.cpp
 *
 *  Created on: 30-Sep-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

int budget,n;
int iter;

void make_table(vector<vector<int> >& table,vector<int>& wt, vector<int>& val)
{
	int i,j;
	for(i = 0;i<=n;i++)
	{
		for(j = 0;j<=budget;j++)
		{
			if(i == 0 || j ==0)
				table[i][j] = 0;
			else
			{
				if(j>=wt[i-1])
					table[i][j] = max(val[i-1] + table[i-1][j-wt[i-1]],table[i-1][j]);
				else
					table[i][j] = table [i-1][j];
			}
		}
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>budget>>n;
    while(budget&&n)
    {
    	iter = 0;
    	vector<int> wt(n) ,val(n);
    	for(int i=0;i<n;i++)
    		cin>>wt[i]>>val[i];
    	vector<vector<int> > table(n+1,vector<int> (budget + 1));
    	make_table(table,wt,val);
    	int maxsum = table[n][budget];
    	int i;
    	for(i=0;i<budget;i++)
    		if(table[n][i] == maxsum)
    			break;
    	cout<<i<<' '<<maxsum<<endl;
    	cin>>budget>>n;
    }

    return 0;
}



