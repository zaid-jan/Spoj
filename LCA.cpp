/*
 * LCA.cpp
 *
 *  Created on: 02-Dec-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

void rz(vector<vector<int> > matrix, int rows, int columns)
{
	matrix.resize(rows);
	for(int i = 0; i<rows; i++)
		matrix[i].resize(columns);
}

void cle(vector<vector<int> > matrix, int rows, int columns)
{
	for(int i = 0; i < rows; i++)
		matrix[i].clear();
	matrix.clear();
}

typedef struct node
{
	vector <int> n;
	int parent;
}NODE;

void addedge(vector<NODE>& graph, int x, int y)
{
	graph[x].n.push_back(y);
	graph[y].n.push_back(x);
	graph[y].parent = x;
}

int goup(vector<NODE>& graph, int x, set<int>& p)
{
	while(x)
	{
		if(p.count(x)>0)
			return x;
		p.insert(x);
		x = graph[x].parent;
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cases = 0;
    while(t--)
    {
    	++cases;
    	int nodes;
    	cin>>nodes;
    	vector <NODE> graph(nodes+1);
    	for(int i = 1; i <= nodes; i++)
    	{
    		int num;
    		cin>>num;
    		for(int j = 1; j<= num; j++)
    		{
        		int y;
        		cin>>y;
        		addedge(graph,i,y);
    		}
    	}
    	set<int> p;
    	int subcase;
    	cin>>subcase;
    	cout<<"Case "<< cases <<':'<<endl;
    	for(int i=0; i<subcase; i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		int result = goup(graph,x,p);
    		result = goup(graph,y,p);
    		cout<<result<<endl;
    		p.clear();
    	}
    }
    return 0;
}


