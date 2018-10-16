#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int a[100001];

int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];

	a[n]=-999;

	ll l=0;
	ll r=0;
	ll i=0;
	while(i<n)
	{
		while(i<n && a[i]<a[i+1])
		{
			i++;
		}
		r=i;
		if(r!=l)
			ans+=(r-l+1)*(r-l)/2;
		i++;
		l=i;
		//cerr<<r<<" "<<ans<<endl;
	}
	ans+=n;
	cout<<ans<<endl;
	return 0;
}