#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n;
	string s[2];
	ll ans=1;
	bool tate;
	
	cin>>n;
	cin>>s[0];
	cin>>s[1];

	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(s[0][i]==s[1][i])
			{
				ans*=3;
				tate=true;
			}else{
				ans*=6;
				i++;
				tate=false;
			}
		}else{
			if(s[0][i]==s[1][i])
			{
				if(tate)
					ans*=2;
				else
					ans*=1;
				tate=true;
			}else{
				if(tate)
					ans*=2;
				else
					ans*=3;
				i++;
				tate=false;
			}
		}
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}