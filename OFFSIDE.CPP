#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, d;
	cin >> a >> d;
	while (a||d)
	{
		vector<int> A(a);
		vector<int> D(d);
		for (int i = 0; i < a; i++)
			cin >> A[i];
		for (int i = 0; i < d; i++)
			cin >> D[i];
		sort(A.begin(), A.end());
		sort(D.begin(), D.end());
		int x = A.front();
		int y = D[1];
		if (x < y)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
		cin >> a >> d;
	}

	return 0;
}