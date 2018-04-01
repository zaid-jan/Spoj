#include <bits/stdc++.h>

#define ll long long;
#define MOD 1000000007;

using namespace std;

int conver(char x)
{
	switch(x)
	{
		case 'a':return 16;
		case 'b':return 17;
		case 'c':return 18;
		case 'd':return 19;
		case 'e':return	20;
		case 'f':return	21;
		case 'g':return	22;
		case 'h':return	23;
		case 'i':return	24;
		case 'j':return	25;
		case 'k':return	26;
		case 'l':return	27;
		case 'm':return	28;
		case 'n':return	20;
		case 'o':return	21;
		case 'p':return	22;
		case 'q':return	23;
		case 'r':return	24;
		case 's':return	25;
		case 't':return	26;
		case 'u':return	18;
		case 'v':return	19;
		case 'w':return	20;
		case 'x':return	21;
		case 'y':return	22;
		case 'z':return	23;
	}
}

int main()
{
	string a;
	while(cin>>a)
	{
		if(a.length() <= 3)
			break;
		int count = 0;
		for(int i = 0;i<a.length();i++)
		{
			int temp = conver(a[i]);
			if(temp>23)
				count++;
			cout<<temp<<' ';
		}
		cout<<endl;
		if(count == 0)
			cout<<"no one."<<endl;
		else
			cout<<count<<endl;		
	}
	return 0;
}