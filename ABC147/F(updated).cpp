#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD = 1e9+7;
map<ll,int> mp;
vector<P> vec[200000];
int main()
{
	int n;
	ll x,d;
	ll ans=0;
	cin>>n>>x>>d;
	if(d==0)
	{
		if(x==0)
			cout<<1<<endl;
		else
			cout<<n+1<<endl;
		return 0;
	}
	if(d<0)
	{
		d*=-1;
		x*=-1;
	}
	int cnt=0;
	for(ll i=0;i<n+1;i++)
	{
		ll l=(i-1)*i/2*d+x*i;
		ll r=(ll)(n-i+n-1)*i/2*d+x*i;
		//cerr<<r<<endl;
		ll md=(x*i)%d;
		if(md<0)
			md+=d;
		if(mp.count(md))
			vec[mp[md]].push_back(P(l,r));
		else{
			mp[md]=cnt;
			cnt++;
			vec[mp[md]].push_back(P(l,r));
		}
	}
	for(int i=0;i<cnt;i++)
	{
		sort(vec[i].begin(),vec[i].end());
		ll l=vec[i][0].first;ll r=vec[i][0].second;
		for(int j=1;j<vec[i].size();j++)
		{
			if(r<vec[i][j].first)
			{
				ans+=(r-l)/d+1;
				l=vec[i][j].first;
				r=vec[i][j].second;
			}else{
				r=max(r,vec[i][j].second);
			}
		}
		ans+=(r-l)/d+1;
	}
	cout<<ans<<endl;
	return 0;
}