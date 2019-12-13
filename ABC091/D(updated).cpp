#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[200000];
ll b[200000];
int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}

	for(int k=28;k>=0;k--)
	{
		ll tmp=0;
		for(int i=0;i<n;i++)
			a[i]%=(1LL<<(k+1));
		for(int i=0;i<n;i++)
			b[i]%=(1LL<<(k+1));
		//aを固定する
		sort(b,b+n);
		for(int i=0;i<n;i++)
		{
			tmp+=lower_bound(b,b+n,(1<<k)*2-a[i])-lower_bound(b,b+n,(1<<k)-a[i]);
			tmp+=lower_bound(b,b+n,(1<<k)*4-a[i])-lower_bound(b,b+n,(1<<k)*3-a[i]);
		}
		if(tmp&1)
			ans+=(1<<k);
	}
	cout<<ans<<endl;
	return 0;
}