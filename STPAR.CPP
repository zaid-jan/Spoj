#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void push(int &x,int &order,vector<int> &stack1,vector<int> &stack2)
{
	if (x == order)
	{
		stack1.push_back(x);
		order++;
	}	
	else
		stack2.push_back(x);
}

void merge(vector<int> &stack1, vector<int> &stack2,int &order)
{
	int x = stack1.back();
	x++;
	for (int i = stack2.size() - 1;i >= 0;i--)
	{
		if (x == stack2[i])
		{
			stack1.push_back(stack2[i]);
			stack2.pop_back();
			x = stack1.back() + 1;
		}
		order = stack1.back();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n)
	{
		vector<int> orig(n), stack1, stack2;
		int order = 1;
		for (int i = 0;i < n;i++)
			cin >> orig[i];
		for (int i = 0;i < n;i++)
		{
			push(orig[i], order, stack1, stack2);
			if(!stack2.empty() && !stack1.empty())
				if (stack1.back()+1 == stack2.back())
					merge(stack1, stack2, order);
		}
		if (!stack2.empty())
			cout << "no" << endl;
		else
			cout << "yes" << endl;
		cin >> n;
	}


	return 0;
}