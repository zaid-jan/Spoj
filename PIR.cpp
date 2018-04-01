/*
 * PIR.cpp
 *
 *  Created on: 28-Oct-2017
 *      Author: zaidjan1295
 */

#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	double W,V,u,U,v,w;
    	cin>>W>>V>>u>>U>>v>>w;
    	double ubar,vbar,wbar;
    	ubar = v*v + w*w - U*U;
    	vbar = w*w + u*u - V*V;
    	wbar = u*u + v*v - W*W;
    	double a,b,c,d,e;
    	a = 4*u*u*v*v*w*w;
    	b = u*u*ubar*ubar;
    	c = v*v*vbar*vbar;
    	d = w*w*wbar*wbar;
    	e = ubar*vbar*wbar;
    	double result = sqrt(a-b-c-d+e)/12;
    	cout<<setprecision(4)<<fixed<<result<<endl;
    }

    return 0;
}


