#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void make_mean(vector<int> &A,float z,int t)
{
	int sum=0,d=0;
	for (int i = 0;i < t;i++)
	{
		if (A[i] == z)
			continue;
		else 
		{
			d = z-A[i];
			A[i] += d;
		}
		if(d>0)
			sum += d;
	}
	bool yo = 1;
	for (int i = A.size() - 1;i >= 0;i--)
		if (A[i] == z)
			yo = yo && 1;
		else
			yo = 0;

	if (yo == 1)
		cout << sum << endl;
	else
		cout << "-1" << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t)
	{
		vector<int> A(t);
		for (int i = 0;i < t;i++)
			cin >> A[i];
		sort(A.begin(), A.end());
		float avg, sum=0;
		for (int i = 0;i < A.size(); i++)
			sum += A[i];
		avg = sum / t;
		make_mean(A, avg, t);
		cin >> t;
	}
	return 0;
}
