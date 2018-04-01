#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> dist;
	long long n;
	cin>>n;
	bool loops = 0;
	while(n>1)
	{
		if(n%2==0)
			n = n/2;
		else
			n = 3*(n+3);

		if(dist.count(n) > 0)
		{
			loops = 1;
			break;
		}

		else
			dist.insert(n);
	}
	if(!loops)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;

	return 0;
}
