#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll t[100];

ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>t[i];
	
	if(n==1)
	{
		ans=t[0];
	}else{
		ll g=gcd(t[0],t[1]);
		ans = t[0]*(t[1]/g);
		for(int i=2;i<n;i++)
		{
			ll g=gcd(ans,t[i]);
			ans = ans*(t[i]/g);
		}
	}
	cout<<ans<<endl;
	return 0;
}