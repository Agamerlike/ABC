#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100000];

int main()
{
	int n;
	ll x;
	ll ans=0;
	
	cin>>n>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=1;i<n;i++)
	{
		if(a[i]+a[i-1]>x)
		{
			ll temp;
			temp=max(0LL,x-a[i-1]);
			ans+=(a[i]-temp);
			a[i]=temp;
			if(a[i]+a[i-1]>x)
			{
				ans+=a[i]+a[i-1]-x;
				a[i-1]-=a[i]+a[i-1]-x;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}