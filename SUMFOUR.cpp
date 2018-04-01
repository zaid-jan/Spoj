/*
 * SUMSFOUR.cpp
 *
 *  Created on: 30-Nov-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define ROWS 4
#define SIZE 16000000

void rz(vector<vector<int> >& matrix, int rows, int columns)
{
	matrix.resize(rows);
	for(int i = 0; i<rows; i++)
		matrix[i].resize(columns);
}

void cle(vector<vector<int> >& matrix, int rows, int columns)
{
	for(int i = 0; i < rows; i++)
		matrix[i].clear();
	matrix.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int> > nums;
    rz(nums,ROWS,n);
    for(int i=0;i<n;i++)
    	for(int j=0;j<ROWS;j++)
    		cin>>nums[j][i];

    unordered_map<int,int> ltable;
    ltable.reserve(SIZE);
    int result;

    vector<int> a;
    for(int i = 0; i<n; i++)
    	for(int j = 0; j<n; j++)
    			ltable[nums[0][i] + nums[1][j]]++;
    int answer = 0;
    for(int i = 0; i<n; i++)
    	for(int j = 0; j<n; j++)
    	{
    			result = - nums[2][i] - nums[3][j];
    			if(ltable.count(result) > 0)
    				answer += ltable[result];

    	}
    cout<<answer<<endl;
    return 0;
}





