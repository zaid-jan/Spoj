/*
 * TRT.cpp
 *
 *  Created on: 03-Oct-2017
 *      Author: zaidjan1295
 */


#include <bits/stdc++.h>

using namespace std;

vector<int> treats;
vector<vector<int> > table;

int dp(int front,int back,int age)
{
	if(front>back)
		return 0;
	if(table[front][back] == -1)
	{
		int sum1 = dp(front+1,back,age+1)+(treats[front]*age);
		int sum2 = dp(front,back-1,age+1)+(treats[back]*age);
		table[front][back] = max(sum1,sum2);
	}
	return table[front][back];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    treats.resize(n);
    table.resize(n+1,vector<int>(n+1,-1));
    for(int i = 0;i<n;i++)
    	cin>>treats[i];
    int result = dp(0,n-1,1);
    cout<<result<<endl;
    return 0;
}

