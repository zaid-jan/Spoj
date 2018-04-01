/*
 * BITMAP.cpp
 *
 *  Created on: 07-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

int rows,columns;

int greedy(vector<vector<int> >& board, vector<vector<int> >& table,int i,int j)
{
	if(i<0 || j<0 || i>=rows || j>=columns)
		return INT16_MAX;
	if(table[i][j] == -1)
	{
		if(board[i][j] == 1)
			table[i][j] = 0;
		else
		{
			int distance1 = 1 + greedy(board,table,i,j+1);
			int distance2 = 1 + greedy(board,table,i+1,j);
			table[i][j] = min(distance1,distance2);
		}
	}
	return table[i][j];
}

void rectify(vector<vector<int> >& board, vector<vector<int> >& table)
{
	for(int i = 0;i<rows;i++)
	{
		for(int j = 0;j<columns;j++)
		{
			int num1,num2,num3,num4;
			if(i<1)
				num1 = INT16_MAX;
			else
				num1 = 1 + table[i-1][j];
			if(j<1)
				num2 = INT16_MAX;
			else
				num2 = 1+ table[i][j-1];
			table[i][j] = min(table[i][j],min(num1,num2));
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	cin>>rows>>columns;
    	vector<vector<int> > board(rows,vector<int>(columns));
    	vector<vector<int> > table(rows,vector<int>(columns,-1));
    	vector<vector<int> > visited(rows,vector<int>(columns));
    	for(int i = 0;i<rows;i++)
    	{
    		string temp;
    		cin>>temp;
    		for(int j = 0;j<columns;j++)
    			board[i][j] = int(temp[j]-'0');
    	}

    	for(int i = 0;i<rows;i++)
    	{
    		for(int j=0;j<columns;j++)
    		{
    		    if(table[i][j] == -1)
    		    	int temp = greedy(board,table,i,j);
    		}
    	}
    	rectify(board,table);
    	for(int i=0;i<rows;i++)
    	{
    		for(int j=0;j<columns;j++)
    		{
    			cout<<table[i][j]<<' ';
    		}
    		cout<<endl;
    	}
    }

    return 0;
}


