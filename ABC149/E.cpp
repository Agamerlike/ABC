#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll a[100000];
ll rui[100001];
int main()
{
	ll n,m;
	ll ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	rui[0]=0;
	for(int i=1;i<n+1;i++)
		rui[i]=rui[i-1]+a[i-1];
	int ok=0;
	int ng=200001;
	while(ng-ok>1)
	{
		int mid=(ng+ok)/2;
		ll cnt=0;
		for(int i=0;i<n;i++)
		{
			int itr=(int)(lower_bound(a,a+n,mid-a[i])-a);
			cnt+=n-itr;
		}
		if(cnt<m)
			ng=mid;
		else
			ok=mid;
	}
	//cerr<<ok<<endl;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		int itr=(int)(lower_bound(a,a+n,ok-a[i])-a);
		ans+=a[i]*(n-itr)+(rui[n]-rui[itr]);
		sum+=(n-itr);
	}
	if(sum>m)
		ans-=(sum-m)*ok;
	cout<<ans<<endl;
	return 0;
}