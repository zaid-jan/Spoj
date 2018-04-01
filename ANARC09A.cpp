/*
 * SEINFELD.cpp
 *
 *  Created on: 21-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

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
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string orig;
    cin>>orig;
    int test = 0;
    while(orig[0]!='-')
    {
    	stack<char> st;
    	int ca=0,cb=0;
    	for(int i = 0; i<orig.length();i++)
    	{
    		if(orig[i] == '{')
    		{
    			ca++;
    			st.push(orig[i]);
    		}
    		else if(orig[i] == '}' && !st.empty() && st.top() == '{')
    		{
    			st.pop();
    			ca--;
    		}
    		else
    		{
    			st.push('{');
    			cb++;
    		}
    	}
    	char sol[2000];
    	int size = st.size();
    	/*int i = 0;
    	while(!st.empty())
    	{
    		sol[i] = st.top();
    		st.pop();
    		i++;
    	}
    	for(int j = i-1; j>=0; j--)
    		cout<<sol[j];
    	cout<<endl;*/
    	cout<<++test<<". "<<size/2 + cb<<endl;
    	cin>>orig;
    }
    return 0;
}



