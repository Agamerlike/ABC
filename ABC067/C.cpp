#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[200000];

bool fun(ll x,ll y)
{
	return abs(x)<abs(y);
}

int main()
{
	int n;
	ll ans=0;
	ll x=0;
	ll y=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l=0;
	int r=n-1;
	x=a[l];
	l++;
	y=a[r];
	r--;
	while(l<=r)
	{
		if(abs((x+a[l])-y)>abs(x-(y+a[r])))
		{
			y+=a[r];
			r--;
		}else{
			x+=a[l];
			l++;
		}
		//cerr<<x<<" "<<y<<endl;
	}

	ans = abs(x-y);
	cout<<ans<<endl;
	return 0;
}