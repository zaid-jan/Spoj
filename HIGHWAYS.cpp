/*
 * HIGHWAYS.cpp
 *
 *  Created on: 09-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ipair pair<int,int>

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

typedef struct node
{
	vector<pair<int, int> > wtadr;
}NODE;

vector<NODE> graph;
vector<int> dist;
int citys, hways, source, dest;


void addwtedge(int x, int y, int wt)
{
	graph[x].wtadr.push_back(make_pair(y,wt));
	graph[y].wtadr.push_back(make_pair(x,wt));
}

void dijsktra(int source)
{
	priority_queue <ipair, vector<ipair>, greater<ipair> > minheap;
	minheap.push(make_pair(0,source));
	dist[source] = 0;
	while(!minheap.empty())
	{
		int u = minheap.top().second;
		minheap.pop();
		for(unsigned int i = 0; i < graph[u].wtadr.size(); i++)
		{
			int v = graph[u].wtadr[i].first;
			int wt = graph[u].wtadr[i].second;
			if(dist[v]>dist[u]+wt)
			{
				dist[v] = dist[u]+wt;
				minheap.push(make_pair(dist[v],v));
			}
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
    	cin>>citys>>hways>>source>>dest;
    	source--;dest--;
    	graph.resize(citys);
    	dist.resize(citys, INT16_MAX);
    	for(int i = 0; i< hways; i++)
    	{
    		int x,y,wt;
    		cin>>x>>y>>wt;
    		x--;y--;
    		addwtedge(x,y,wt);
    	}
    	dijsktra(source);
    	if(dist[dest] == INT16_MAX)
    		cout<<"NONE"<<'\n';
    	else
    		cout<<dist[dest]<<'\n';
    	graph.clear();
    	dist.clear();
    }

    return 0;
}



