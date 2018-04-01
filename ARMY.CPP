#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		cout << endl;
		int gsize, msize;
		cin >> gsize >> msize;
		vector<int> garmy(gsize), marmy(msize);
		for (int i = 0;i < gsize;i++)
			cin >> garmy[i];
		for (int i = 0;i < msize;i++)
			cin >> marmy[i];
		sort(garmy.begin(), garmy.end());
		sort(marmy.begin(), marmy.end());
		if (garmy.back() > marmy.back() || garmy.back() == marmy.back())
			cout << "Godzilla" << endl;
		else
			cout << "MechaGodzilla" << endl;
	}

	return 0;
}