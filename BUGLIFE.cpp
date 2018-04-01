/*
 * BUGLIFE.cpp
 *
 *  Created on: 05-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

string flip(string s)
{
	if(s == "male")
		return "female";
	return "male";
}

struct graphnode
{
	vector<int> nei;
	string color;
	int layer;
};

void addedge(vector<graphnode>& graph, int x, int y)
{
	graph[x].nei.push_back(y);
	graph[y].nei.push_back(x);
}

void make_graph(vector<graphnode>& graph, int edges)
{
	for(int i = 0;i<edges;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(graph,x-1,y-1);
	}
}

bool bip(vector<graphnode>& graph, int source)
{
	int layer = 0;
	queue<int> q;
	graph[source].color = "male";
	graph[source].layer = layer;
	visited[source] = true;
	q.push(source);
	while(!q.empty())
	{
		layer++;
		int current = q.front();
		q.pop();
		string nextcolor = flip(graph[current].color);
		for(int i = 0;i<graph[current].nei.size();i++)
		{
			int next = graph[current].nei[i];
			if(!visited[next])
			{
				q.push(next);
				graph[next].layer = layer;
				visited[next] = true;
				graph[next].color = nextcolor;
			}
			else if(visited[next])
			{
				if(graph[current].layer == graph[next].layer);
					if(graph[current].color == graph[next].color)
							return true;
			}


		}
	}
	return false;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int sce = 0;
    while(t--)
    {
    	sce++;
    	int nodes,edges;
    	cin>>nodes>>edges;
    	visited.resize(nodes,false);
    	vector<graphnode> graph(nodes);
    	make_graph(graph,edges);
    	bool found = false;
    	for(int i=0;i<nodes;i++)
    		if(visited[i] == false)
    		{
    			int source = i;
    			string color = graph[source].color;
    			found = found || bip(graph,i);
    		}
    	cout<<"Scenario #"<<sce<<":"<<endl;
    	if(found)
    		cout<<"Suspicious bugs found!"<<endl;
    	else
    		cout<<"No suspicious bugs found!"<<endl;
    	visited.clear();
    }

    return 0;
}



