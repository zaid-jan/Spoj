/*
 * GLJIVE.cpp
 *
 *  Created on: 13-Nov-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

#define SIZE 10
#define MAX 100
/*void rz()
{
	matrix.resize(rows);
	for(int i = 0; i<rows; i++)
		matrix[i].resize(columns);
}

void cle()
{
	for(int i = 0; i < rows; i++)
		matrix[i].clear();
	matrix.clear();
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums(SIZE);
    for(int i = 0; i< SIZE; i++)
    	cin>>nums[i];
    int sum = 0;
    int result = 100;
    int diff = INT16_MAX;
    for(int i = 0; i<SIZE; i++)
    {
    	sum += nums[i];
    	if(abs(sum -  MAX) <= diff)
    	{
    		diff = abs(sum - MAX);
    		result = sum;
    	}
    	else
    		break;
    }
    cout<<result<<'\n';


    return 0;
}


