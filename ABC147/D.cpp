#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll a[300000];
ll cnt[61];
ll pw[61];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	//それぞれの桁を調べる
	fill(cnt,cnt+64,0LL);
	for(int i=0;i<n;i++)
	{
		for(ll j=0;j<61;j++)
		{
			if(a[i]&(1LL<<j))
				cnt[j]++;
		}
	}
	for(int i=0;i<61;i++)
	{
		pw[i]=(1LL<<(ll)i)%MOD;
	}
	for(int i=0;i<61;i++)
	{
		//cerr<<(1LL<<(ll)i)<<" "<<cnt[i]<<endl;
		ll tmp=pw[i]*cnt[i];
		tmp%=MOD;
		tmp*=((ll)n-cnt[i]);
		tmp%=MOD;
		ans+=tmp;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}