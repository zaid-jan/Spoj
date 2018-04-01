/*
 * CSTREET.cpp
 *
 *  Created on: 07-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

vector<int> disj;

typedef struct graph_node
{
	pair<int,int> edges;
	int length;
}NODE;

bool asc(NODE a, NODE b)
{
	return a.length<b.length;
}

int find(int x)
{
	if(disj[x] == -1)
		return x;
	return find(disj[x]);
}

void unio(int x, int y)
{
	disj[y] = x;
}

int kurk(vector<NODE>& graph)
{
	int sum = 0;
	for(int i = 0; i<graph.size(); i++)
	{
		int x = find(graph[i].edges.first);
		int y = find(graph[i].edges.second);
		if(x == y)
			continue;
		sum += graph[i].length;
		unio(x,y);
	}
	return sum;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int price,nodes,edges;
    	cin>>price>>nodes>>edges;
    	vector<NODE> graph(edges);
    	for(int i = 0; i < edges; i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		x--;y--;
    		graph[i].edges.first = x;
    		graph[i].edges.second = y;
			cin>>graph[i].length;

    	}
    	sort(ALL(graph),asc);
    	disj.resize(nodes,-1);
    	int result = kurk(graph);
    	result *= price;
    	cout<<result<<'\n';
    	disj.clear();
    }

    return 0;
}



