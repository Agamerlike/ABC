#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[200000];
ll x[200000];//i以下の和

int main()
{
	int n;
	ll ans=99999999999999;
	fill(x,x+200000,0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		x[i]=a[i];
		if(i>0)
			x[i]+=x[i-1];
	}

	for(int i=0;i<n-1;i++)
	{
		ll t = abs(x[n-1]-x[i]-x[i]);
		if(t<ans)
			ans=t;
	}

	
	cout<<ans<<endl;
	return 0;
}