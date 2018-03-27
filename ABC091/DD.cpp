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

int bound(ll t,int n)
{
	int l,r,mid;
	l=0;
	r=n;
	while(l<r)
	{
		mid=(l+r)/2;
		if(b[mid]>t)
		{
			r=mid;
		}else{
			l=mid;
		}
	}
	return l;
}

int main()
{
	int n;
	ll t1,t2,t3,t4;
	ll ans=0;
	ll amod,bmod;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(b,b+n);

	for(int i=0;i<n;i++)
	{
		for(int bit=0;bit<28;bit++)
		{
			t1=pow(2,bit+1);
			t2=t1*2;
			t3=t1*3;
			t4=t1*4;
			amod = a[i]%pow(2,bit+1);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}