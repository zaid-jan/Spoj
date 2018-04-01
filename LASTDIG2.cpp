#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	string a,b;
    	cin>>a>>b;
    	int alast = a.back() - '0';
    	int blast;
    	int blength = b.length();
    	if(blength == 1)
    		blast = b.back() - '0';
    	else
    		blast = b[blength - 2]*10 + b[blength - 1] - '0';
    	if(blast == 0 && alast == 0)
    		cout<<0<<endl;
    	else if (blast == 0 && alast != 0)
    		cout<<1<<endl;
    	else
    	{
    		int result;
    		blast = blast%4;
    		if(blast == 0)
    		{
    			result = pow(alast,4);
    			cout<<result%10<<endl;
    		}
    		else
    		{
    			result = pow(alast,blast);
    			cout<<result%10<<endl;
    		}
    	}
    }

    return 0;
}


