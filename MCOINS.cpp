/*
 * MCOINS.cpp
 *
 *  Created on: 27-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

int k,l,m;
int msize = -1;

void wldp(vector<int>& wl)
{
	wl[0] = 0;
	wl[1] = 1;
	for(int i = 1; i<=msize;i++)
	{
		if(i-k>=0 && wl[i - k] == 0)
			wl[i] = 1;
		if(i-l >= 0 && wl[i - l] == 0)
			wl[i] = 1;
		if(i-1>=0 && wl[i-1] == 0)
			wl[i] = 1;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>l>>m;
    vector<int> sizes(m);
    for(int i = 0;i<m;i++)
    {
    	cin>>sizes[i];
    	msize = max(msize,sizes[i]);
    }
    vector<int> wl(msize+1);
    wldp(wl);
    for(int i = 0;i<m;i++)
    {
    	if(wl[sizes[i]] == 1)
    		cout<<"A";
    	else
    		cout<<"B";
    }
    cout<<endl;
    return 0;
}



