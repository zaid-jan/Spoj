/*
 * PT07Y.cpp
 *
 *  Created on: 31-Aug-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

void add_edge(int a, int b, vector<vector<int> >& graph)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
}


void find_cycle(vector<vector<int> >& graph, vector<int>& parents,vector<int>& visited, int i, int& cycle_detected)
{
	int j;
	for(j=0;j<graph[i].size();j++)
	{
		int z = graph[i][j];
		if(!visited[z])
		{
			parents[z] = i;
			visited[z] = 1;
			find_cycle(graph,parents,visited,z,cycle_detected);
		}
		else
		{
			if(parents[z]==i)
				cycle_detected = 1;
		}
	}
	return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cycle_detected = 0;
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n);
    vector<int> visited(n,0);
    vector<int> parents(n);

    for(int i=0;i<m;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	x--;y--;
    	add_edge(x,y, graph);
    }
    parents[0] = -1;
    visited[0] = 1;
    if(m != n-1 || n == 1)
    	cout<<"NO"<<endl;
    else
    {
    	find_cycle(graph,parents,visited,0,cycle_detected);
    	if(cycle_detected)
    	    cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    }
    return 0;
}
