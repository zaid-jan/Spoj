/*
 * DANGER.cpp
 *
 *  Created on: 01-Nov-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()

ll num;

/*ll solve(vector<int>& doa)
{
	bool found = false;
	ll i = 0;
	ll count = 0;
	ll iter = 0;;
	while(count!=num)
	{
		if(found && doa[i] != 1)
		{
			doa[i] = 1;
			found = false;
		}
		if(doa[i] == 0)
		{
			found = true;
			count = 0;
			iter = i;
		}
		i = (i+1)%num;
		count++;
	}
	return iter;
}*/

ll solve(ll num)
{
	ll factor = log2(num);
	ll loop = pow(2,factor);
	ll odd = 1;
	odd += (num - loop)*2;
	return odd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string number;
    cin>>number;
    while(number!="00e0")
    {
    	num = (number[0]-'0')*10+(number[1]-'0');
    	num *= pow(10,(number[3]-'0'));
    	ll result = solve(num);
    	cout<<result<<'\n';
    	cin>>number;
    }

    return 0;
}



