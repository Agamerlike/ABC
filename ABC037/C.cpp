#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	ll n,k;
	ll a[100000];
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	ll l=k-1;
	ll r=n-k+1;//k回足される区間を求める[l,r)
	if(l<=r)
	{
		for(ll i=0;i<l;i++)
			ans+=a[i]*(i+1);
		for(ll i=0;i<l;i++)
			ans+=a[n-1-i]*(i+1);
		for(int i=l;i<r;i++)
			ans+=a[i]*k;
	}else{
		int cnt=0;
		for(ll i=0;i<r;i++)
		{
			ans+=a[i]*(i+1);
			cnt=i+1;
		}
		//cerr<<cnt<<endl;
		for(ll i=0;i<r;i++)
			ans+=a[n-1-i]*(i+1);
		for(int i=r;i<l;i++)
			ans+=a[i]*cnt;
	}
	cout<<ans<<endl;
	return 0;
}