#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll MOD = 1e9+7;
map<P,ll> mp;
ll func(ll s,ll x)
{
	if(mp.count(P(s,x))>0)
		return mp[P(s,x)];
	else{
		//cerr<<s<<" "<<x<<endl;
		mp[P(s,x)]=(func(s/2LL,x/2LL)+func((s-1LL)/2LL,(x-1LL)/2LL))%MOD;
		if(s>=2)
		{
			mp[P(s,x)]+=func((s-2LL)/2LL,x/2LL);
			mp[P(s,x)]%=MOD;
		}
		if(mp[P(s,x)]<0)
			mp[P(s,x)]+=MOD;
		return mp[P(s,x)];
	}
}
int main()
{
	ll n;
	cin>>n;
	mp[P(0,0)]=1;
	mp[P(0,1)]=1;
	mp[P(1,0)]=1;
	mp[P(1,1)]=2;
	mp[P(2,0)]=3;
	mp[P(2,1)]=3;
	mp[P(2,2)]=4;
	mp[P(0,2)]=1;
	mp[P(1,2)]=2;
	ll ans=func(n,n);
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}