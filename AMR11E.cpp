/*
 * AMR11E.cpp
 *
 *  Created on: 09-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

#define SIZE 3001
#define MAX 100000

vector<int> primes;
vector<int> lucky(1001);

void seive()
{
	vector <int> sei(SIZE+1,1);
	sei[0] = 0;
	sei[1] = 0;
	for(int i = 2; i<=SIZE;  i++)
	{
		if(sei[i] == 1)
		{
			primes.push_back(i);
			for(int j = i; j<=SIZE; j+=i)
				sei[j] = 0;
		}
	}
}
void create()
{
    int iter = 0;
    for(int i = 30;i<=MAX;i++)
    {
    	int count = 0;
    	for(int j = 0;j<primes.size(); j++)
    	{
    		if(primes[j]>i)
    			break;
    		if(i%primes[j] == 0)
    			count++;
    		if(count >= 3)
    		{
    			lucky[iter] = i;
    			iter++;
    			break;
    		}
       	}
    	if(iter>1000)
   			break;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    seive();
    create();
    while(t--)
    {
    	int len = primes.size();
    	int n;
    	cin>>n;
    	cout<<lucky[n-1]<<endl;
    }

    return 0;
}



