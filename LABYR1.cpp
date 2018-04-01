/*
 * LABYR1.cpp
 *
 *  Created on: 11-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

vector<vector<char> > matrix;
vector<vector<int> > visited;
vector<vector<int> > distances;

typedef struct
{
	int x, y;
	int dist;
} CORD;

CORD trav;

int rows,columns;

void rz()
{
	matrix.resize(rows);
	for(int i = 0; i<rows; i++)
		matrix[i].resize(columns);
	visited.resize(rows);
	for(int i = 0; i<rows; i++)
		visited[i].resize(columns);
	distances.resize(rows);
	for(int i = 0; i<rows; i++)
		distances[i].resize(columns, INT16_MAX);
}

void cle()
{
	for(int i = 0; i < rows; i++)
		matrix[i].clear();
	matrix.clear();
	for(int i = 0; i < rows; i++)
		visited[i].clear();
	visited.clear();
	for(int i = 0; i < rows; i++)
		distances[i].clear();
	distances.clear();

}

void get_input()
{
	for(int i = 0; i<rows; i++)
	{
		string temp;
		cin>>temp;
		for(int j = 0; j<columns; j++)
		{
			matrix[i][j] = temp[j];
			if(matrix[i][j] == '.')
			{
				trav.x=i;
				trav.y=j;
				trav.dist=0;
			}
		}
	}
}

int check(int i, int j)
{
	if(i<0 || i >= rows || j<0 || j >= columns)
		return 0;
	return 1;
}

void valid(int i, int j, int dist)
{
	if(dist>trav.dist)
	{
		trav.x = i;
		trav.y = j;
		trav.dist = dist;
	}
}

void reset()
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			visited[i][j] = 0;

}


void bfs(int x, int y, int dist)
{
	queue<CORD> q;
	CORD temp;
	temp.x = x; temp.y = y; temp.dist = dist;
	q.push(temp);
	while(!q.empty())
	{
		int i = q.front().x;
		int j = q.front().y;
		int dist = q.front().dist;
		distances[i][j] = dist;
		q.pop();
		visited[i][j] = 1;
		if(matrix[i][j] == '.')
			valid(i,j,dist);

		if(check(i-1,j) && !visited[i-1][j] && matrix[i-1][j] == '.')//go up
		{
			temp.x = i-1; temp.y = j; temp.dist = dist+1;
			q.push(temp);
		}

		if(check(i,j+1) && !visited[i][j+1] && matrix[i][j+1] == '.')//go right
		{
			temp.x = i; temp.y = j+1; temp.dist = dist+1;
			q.push(temp);
		}

		if(check(i+1,j) && !visited[i+1][j] && matrix[i+1][j] == '.')//go down
		{
			temp.x = i+1; temp.y = j; temp.dist = dist+1;
			q.push(temp);
		}

		if(check(i,j-1) && !visited[i][j-1] && matrix[i][j-1] == '.')//go left
		{
			temp.x = i; temp.y = j-1; temp.dist = dist+1;
			q.push(temp);
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
    	cin>>columns>>rows;
    	rz();
    	get_input();
    	bfs(trav.x,trav.y,0);
    	CORD source = trav;
    	trav.x = 0;trav.y = 0;trav.dist = 0;
    	reset();
    	bfs(source.x,source.y,0);
    	CORD dest = trav;
    	cout<<"Maximum rope length is "<<dest.dist<<'.'<<endl;
    	cle();
    }
    return 0;
}



