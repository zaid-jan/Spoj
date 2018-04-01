#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string comp(string a, int i, char* z)
{
	int y = i + 3;
	int j;
	for (i, j = 0;i < y;i++, j++)
		z[j] = a[i];
	return string(z,z+3);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int TTT = 0, TTH = 0, THT = 0, THH = 0, HTT = 0, HTH = 0, HHT = 0, HHH = 0;
		string a;
		cin >> a;
		char y[3];
		for (unsigned int i = 0;i < a.length() - 2;i++)
		{
			string z = comp(a, i, y);
			if (z == "TTT")
				TTT++;
			if (z == "TTH")
				TTH++;
			if (z == "THT")
				THT++;
			if (z == "THH")
				THH++;
			if (z == "HTT")
				HTT++;
			if (z == "HTH")
				HTH++;
			if (z == "HHT")
				HHT++;
			if (z == "HHH")
				HHH++;
		}
		cout << n << " " << TTT << ' ' << TTH << ' ' << THT << ' ' << THH << ' ' << HTT << ' ' << HTH << ' ' << HHT << ' ' << HHH << endl;
	}

	return 0;
}