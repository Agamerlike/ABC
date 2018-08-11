#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

ll a[100000];
ll rui[100001];
bool f[100001];
map<ll,ll> mm;

int main()
{
	int n;
	ll m;
	ll ans=0;
	cin>>n>>m;
	fill(rui,rui+100001,0);
	fill(f,f+100001,false);
	for(int i=0;i<n;i++)
		cin>>a[i];
	rui[0]=0;
	for(int i=1;i<n+1;i++)
		rui[i]=rui[i-1]+a[i-1];
	
	if(rui[n]==m)
	{
		cout<<1<<endl;
		return 0;
	}

	if(rui[n]<m)
	{
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=0;i<n+1;i++)
		rui[i]%=m;

	for(int i=0;i<n+1;i++)
	{
		mm[rui[i]]++;
	}
	
	for(auto itr=mm.begin();itr != mm.end();++itr)
	{
		ll v=itr->second;
		if(v>=2)
		{
			ans+=v*(v-1)/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}