/*
 * DIEHARD.cpp
 *
 *  Created on: 26-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define LIM 2100

vector<vector<int> > table(LIM);

void air(int& health,int& armour)
{
	health += 3;
	armour += 2;
}
void water(int& health,int& armour)
{
	health -= 5;
	armour -= 10;
}

void fire(int& health,int& armour)
{
	health -= 20;
	armour += 5;
}

int maxtime(int health, int armour, int current, int time)
{
	if(table[health][armour]==-1)
	{
		if(current == 2)
		{
			air(health, armour);
			if(health<=0 || armour<=0)
				return time;
			else
			{
				int result1 = maxtime(health, armour,0,time+1);
				int result2 = maxtime(health, armour,1,time+1);
				table[health][armour] = max(result1,result2);
			}
		}
		else if(current == 1)
		{
			water(health, armour);
			if(health<=0 || armour<=0)
				return time;
			else
				table[health][armour] = maxtime(health, armour,2,time+1);
		}
		else
		{
			fire(health, armour);
			if(health<=0 || armour<=0)
				return time;
			else
				table[health][armour] =  maxtime(health, armour,2,time+1);
		}
	}
	return table[health][armour];
}

void rz()
{
	for(int i = 0;i < LIM; i++)
	    table[i].resize(LIM,-1);
}

void clr()
{
	for(int i = 0;i<LIM;i++)
	    table[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int health,armour;
    	cin>>health>>armour;
    	rz();
    	int result = maxtime(health,armour,2,0);
    	cout<<result<<endl;
    	clr();
    }

    return 0;
}


