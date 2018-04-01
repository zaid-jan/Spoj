/*
 * FACEFRND.cpp
 *
 *  Created on: 03-Oct-2017
 *      Author: zaidjan1295
 */


#include <bits/stdc++.h>

using namespace std;

void insert_fof(set<string>& f, set<string>& fof,string temp)
{
	if(f.find(temp)==f.end())
		fof.insert(temp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    set<string> fof,f;
    vector<string> array;
    while(t--)
    {
    	string temp;
    	cin>>temp;
    	f.insert(temp);
    	int n;
    	cin>>n;
    	while(n--)
    	{
    		string temp2;
    		cin>>temp2;
    		array.push_back(temp2);
    	}
    }
    for(int i =0;i<array.size();i++)
        insert_fof(f,fof,array[i]);
    cout<<fof.size()<<endl;

    return 0;
}

