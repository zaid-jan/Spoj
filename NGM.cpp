/*
 * NGM.cpp
 *
 *  Created on: 30-Nov-2017
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    if(n%10 == 0)
    	cout<<2<<endl;
    else
    {
    	cout<<1<<endl;
    	cout<<n%10<<endl;
    }
    return 0;
}


