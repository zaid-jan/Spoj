#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class it
{
public:
	int level = 0;
	int iter;
};

class graph
{
public:
	int iterator, length, yn = 0, level = 0;
	vector<int> adress;
};

it max(it a, it b)
{
	if (a.level > b.level)
		return a;
	else
		return b;
}

void clgraph(vector<graph> &A)
{
	for (unsigned int i = 0;i < A.size();i++)
		A[i].yn = 0;
}

void addedge(vector<graph> &A,int x,int y)
{
	A[x-1].adress.push_back(y-1);
	A[y-1].adress.push_back(x-1);
}
/**********************************************************************************************************************************/
it dfsnode(vector<graph> &A, int curr,int prev)
{
	if (A[curr].yn == 1)
	{
		it o;
		o.level = A[curr].level;
		o.iter = A[curr].iterator;
		return o;
	}
	else
	{
		stack<int> st;
		for (unsigned int i = 0;i < A[curr].adress.size();i++)
			if(A[A[curr].adress[i]].yn==0)
				st.push(A[curr].adress[i]);
		A[curr].yn = 1;
		it  x;
		x.level = A[curr].level;
		x.iter = A[curr].iterator;
		while (!st.empty())
		{
			int next = st.top();
			st.pop();
			A[next].level = A[curr].level + 1;
			x = max(dfsnode(A, next, A[curr].iterator),x);
		}
		return x;
	}
}
/*******************************************************************************************************************************/
int dfslength(vector<graph> &A, int curr, int prev)
{
	if (A[curr].yn == 1)
		return A[curr].length;
	else
	{
		stack<int> st;
		for (unsigned int i = 0;i < A[curr].adress.size();i++)
			if (A[A[curr].adress[i]].yn == 0)
				st.push(A[curr].adress[i]);
		A[curr].yn = 1;
		int x = A[curr].length;
		while (!st.empty())
		{
			int next = st.top();
			st.pop();
			A[next].length = A[curr].length + 1;
			x = max(dfslength(A, next, A[curr].iterator), x);
		}
		return x;
	}
}
/*******************************************************************************************************************************/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<graph> A(n);

	for (int i = 0;i < n-1;i++)
	{
		int x, y;
		cin >> x >> y;
		addedge(A, x, y);
	}
	for(int i=0;i<n;i++)
		A[i].iterator = i;
	int start = 0;
	int min = INT16_MIN;
	it level =  dfsnode(A,start,min);
	int x = level.iter;
	clgraph(A);
	int y = dfslength(A, x, min);
	cout << y << endl;
	return 0;
}