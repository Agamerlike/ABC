#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
pair<ll,ll> ab[100000];
int main()
{
	int n;
	ll m;
	cin>>n>>m;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll a;
		ll b;
		cin>>a>>b;
		ab[i]=make_pair(a,b);
	}
	sort(ab,ab+n);
	ll now=0;
	int i=0;
	while(now<m)
	{
		now+=ab[i].second;
		ans+=ab[i].second*ab[i].first;
		if(now>m)
		{
			ans-=ab[i].first*(now-m);
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}