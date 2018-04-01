/*
 * ABCPATH.cpp
 *
 *  Created on: 01-Nov-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

vector<vector<int> > grid;
vector<vector<int> > visited;
vector<vector<int> > table;

int n,m;

int check(int i, int j)
{
	if(i<0 || i>= n || j<0 || j>=m)
			return 0;
	return 1;
}

int dp(int i, int j)
{
	if(i<0 || i>= n || j<0 || j>=m)
		return 0;

	if(table[i][j] == -1)
	{
		if(visited[i][j])
			return 0;
		visited[i][j] = 1;
		int sum = 1;

		int ch = grid[i][j];
		if(ch == int('Z'))
				return 1;

		if(check(i-1,j) && grid[i-1][j] == ch+1) //up
			sum  = max(sum, dp(i-1,j)+1);

		if(check(i-1,j+1) && grid[i-1][j+1] == ch+1 ) //digonal up right
			sum = max(sum, dp(i-1,j+1)+1);

		if(check(i,j+1) && grid[i][j+1] == ch+1 ) //right
			sum = max(sum, dp(i,j+1)+1);

		if(check(i+1,j+1) && grid[i+1][j+1] == ch+1) //diagonal down right
			sum = max(sum, dp(i+1,j+1)+1);

		if(check(i+1,j) && grid[i+1][j] == ch+1) //down
			sum = max(sum, dp(i+1,j)+1);

		if(check(i+1,j-1) && grid[i+1][j-1] == ch+1 ) //diagonal down left
			sum = max(sum, dp(i+1,j-1)+1);

		if(check(i,j-1) && grid[i][j-1] == ch+1 ) //left
			sum = max(sum, dp(i,j-1)+1);

		if(check(i-1,j-1) && grid[i-1][j-1] == ch+1) //diagonal up left
			sum = max(sum, dp(i-1,j-1)+1);
		table[i][j] = sum;
	}
	return table[i][j];
}

void rz()
{
	grid.resize(n);
	for(int i = 0; i<n;i++)
		grid[i].resize(m);
	visited.resize(n);
	for(int i = 0; i<n; i++)
	    visited[i].resize(m);
	table.resize(n);
	for(int i = 0; i<n; i++)
		table[i].resize(m,-1);
}

void cle()
{
	for(int i = 0; i<n; i++)
		grid[i].clear();
	grid.clear();
	for(int i = 0; i<n; i++)
		visited[i].clear();
	visited.clear();
	for(int i = 0; i<n; i++)
		table[i].clear();
	table.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c = 0;
    cin>>n>>m;
    while(n && m)
    {
    	c++;
    	rz();
    	for(int i = 0; i < n;i++)
    	{
    		string temp;
    		cin>>temp;
    		for(int j = 0; j<m; j++)
    			grid[i][j] = int(temp[j]);
    	}
    	int result = 0;
    	for(int i = 0; i<n; i++)
    		for(int j = 0; j<m; j++)
    			if(grid[i][j] == int('A'))
    				result = max(result, dp(i,j));
    	cout<<"Case "<<c<<": "<<result<<'\n';
    	cle();

    	cin>>n>>m;
    }

    return 0;
}


