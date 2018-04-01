/*
 * ACPC10D.cpp
 *
 *  Created on: 27-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define TRI 3

vector<vector<int> > orig;
vector<vector<int> > table;
int n;
void rz()
{
	orig.resize(n);
	table.resize(n);
	for(int i = 0;i<n;i++)
	{
		orig[i].resize(TRI);
		table[i].resize(TRI,INT16_MIN);
	}
}
void cle()
{
	for(int i = 0; i<n; i++)
	{
		orig[i].clear();
		table[i].clear();
	}
	orig.clear();
	table.clear();
}

int check(int i, int j)
{
	if(i>=n)
		return 0;
	if(j<0 || j>=TRI)
		return 0;
	return 1;
}

int dp(int i, int j)
{
	if(table[i][j] == INT16_MIN)
	{
		if(i == n-1)
			if(j == 1)
				return orig[i][j];
			else if(j == 0)
				return orig[i][j] + dp(i,j+1);
			else
				return INT16_MAX;

		int sum1,sum2,sum3,sum4;

		if(check(i,j+1))
			sum1 = orig[i][j] + dp(i,j+1);//go right
		else
			sum1 = INT16_MAX;
		if(check(i+1,j))
			sum2 = orig[i][j] + dp(i+1,j);//go down
		else
			sum2 = INT16_MAX;
		if(check(i+1,j-1))
			sum3 = orig[i][j] + dp(i+1,j-1);//go diagonal left
		else
			sum3 = INT16_MAX;
		if(check(i+1,j+1))
			sum4 = orig[i][j] + dp(i+1,j+1);//go diagonal right
		else
			sum4 = INT16_MAX;

		table[i][j] = min(sum1,min(sum2,min(sum3,sum4)));
	}
	return table[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    cin>>n;
    while(n)
    {
    	count++;
    	rz();

    	for(int i = 0;i < n; i++)
    		for(int j = 0; j < TRI; j++)
    			cin>>orig[i][j];
    	int result = dp(0,1);

    	cout<<count<<". "<<result<<endl;
    	cle();
    	cin>>n;
    }

    return 0;
}


