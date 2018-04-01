#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<long long> count_inv(vector<long long> &left, vector<long long> &right, long long &count);

vector<long long> split(vector<long long> &A, long long &count)
{
	if (A.size() == 1)
		return A;
	else
	{
		int mid = A.size() / 2;
		int umid = A.size() - mid;
		/*vector<long long> *left, *right;
		left = new vector<long long>(mid);
		right = new vector<long long>(umid);*/
		vector <long long> left(mid), right(umid);	
		for (int i = 0;i < mid;i++)
			(left)[i] = A[i];
		for (int i = mid, j = 0;i < A.size();i++, j++)
			(right)[j] = A[i];
		vector<long long> l = split(left, count);
		vector<long long> r = split(right, count);
		l.push_back(LLONG_MAX);
		r.push_back(LLONG_MAX);
		vector<long long> C = count_inv(l, r, count);
		return C;
	}
}

vector<long long> count_inv(vector<long long> &left, vector<long long> &right, long long &count)
{
	/*vector<long long> *merged;
	merged = new vector<long long>(left.size() + right.size() - 2);*/
	vector<long long> merged(left.size() + right.size() - 2);
	int i = 0, j = 0, k = 0;
	while (i + j != left.size() + right.size() - 2)
	{
		if (left[i] < right[j])
		{
			(merged)[k] = left[i];
			i++;k++;
		}
		else if (left[i] > right[j])
		{
			(merged)[k] = right[j];
			j++;k++;count += left.size()-i-1;
		}
		else
		{
			(merged)[k] = left[i];
			(merged)[k + 1] = right[j];
			i++;j++;k += 2;
		}
	}
	return merged;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		cout << endl;
		int n;
		cin >> n;
		vector<long long> A(n);
		for (int i = 0;i < n;i++)
			cin >> A[i];
		long long count = 0;
		vector<long long> S = split(A, count);
		cout << count << endl;

		for (int i = 0;i < n;i++)
			cout << S[i] << " ";
	}

	return 0;
}