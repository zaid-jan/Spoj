/*
 * ACODE.cpp
 *
 *  Created on: 27-Aug-2017
 *      Author: zaidjan1295
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int size;

int dp(string line, vector<long long> &mem, int i)
{
	if(mem[i]==-1)
	{
		if(i==size)
			mem[i] = 1;
		else if((int)(line[i] - '0')*10 + (int)(line[i+1]-'0')<=26 && line[i] != '0' && i+1 <= size && i+2 <=size)
			mem[i] = dp(line, mem, i+1) + dp(line, mem, i+2);
		else if(line[i] > '0')
			mem[i] = dp(line, mem, i+1);
		else if(line[i] == '0')
			mem[i] = LONG_LONG_MIN;
	}
		return mem[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    while(t)
    {
    	//float t1 = clock();
    	string linea;
    	line = to_string(t);
    	vector<long long> mem(line.length() + 1,-1);
    	size = line.length();
    	long long result;
    	result = dp(line, mem, 0);
    	if(result<0)
    		cout<<'0'<<'\n';
    	else
    		cout<<result<<'\n';
    	//float t2 = clock();
    	//float clock = t2 - t1;
    	//cout<<clock/CLOCKS_PER_SEC<<endl;
    	cin>>t;
    }
    return 0;
}


