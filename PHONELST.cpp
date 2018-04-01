/*
 * PHONELST.cpp
 *
 *  Created on: 26-Oct-2017
 *      Author: zaidjan1295
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZE 10

struct node
{
	vector<struct node*> digits = vector<struct node*>(SIZE);
	int isnum = 0;
	int outgoing;
};

bool found = false;
struct node initial;

int exists(struct node* trav, int i)
{
	if(trav->digits[i] == 0)
		return 0;
	return 1;
}

struct node* cre()
{
	struct node* ptr;
	ptr = new struct node;
	return ptr;
}

void ctrie(string num)
{
	struct node* trav = &initial;
	int len = num.length();
	for(int i=0;i<=len;i++)
	{
		int it = num[i] - '0';
		bool cond1 = trav->isnum && num[i] != '\0';
		bool cond2 = trav->outgoing && num[i] == '\0';
		if(cond1 || cond2)
		{
			found = 1;
			break;
		}
		else
		{
			if(num[i] == '\0')
				trav->isnum = 1;
			else if(exists(trav,it))
				trav = trav->digits[it];
			else
			{
				trav->digits[it] = cre();
				trav->outgoing = 1;
				trav = trav->digits[it];
			}
		}
	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	vector<string> nums(n);
    	for(int i = 0;i<n;i++)
    		cin>>nums[i];
    	for(int i = 0;i<n;i++)
    	{
    		ctrie(nums[i]);
    		if(found)
    			break;
    	}

    	if(found)
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    	found = false;
    	for(int i =0;i<SIZE;i++)
    		initial.digits[i] = 0;
    }
    return 0;
}



