#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	ll n;
	ll sqn;
	ll a,b;
	ll ans=9999999;
	ll i=2;
	ll keta;
	a=1;
	b=1;
	
	cin>>n;
	sqn=sqrt(n);
	while(i<=sqn)
	{
		if(n%i==0)
		{
			a=i;
			b=n/i;
			keta=max((ll)log10(a),(ll)log10(b))+1;
			if(keta<ans)
				ans=keta;
		}
		i++;
	}
	if(ans==9999999)
	{
		a=n;
		b=1;
		ans = (ll)log10(a)+1;
	}
	cout<<ans<<endl;
	return 0;
}