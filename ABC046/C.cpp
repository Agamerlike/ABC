#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll t[1000];
ll a[1000];

int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>t[i]>>a[i];
	
	for(int i=1;i<n;i++)
	{
		ll tt=t[i];
		ll aa=a[i];
		//逆転の解消
		ll mul=max(t[i-1]/t[i]+(t[i-1]%t[i]>0),a[i-1]/a[i]+(a[i-1]%a[i]>0));
		//cerr<<mul<<endl;
		t[i]*=mul;
		a[i]*=mul;
		
		//この部分いらなかった
		/*
		//得票数を求める
		while(t[i]<t[i-1] && a[i]<a[i-1])
		{
			t[i]+=tt;
			a[i]+=aa;
		}
		*/
	}
	ans=t[n-1]+a[n-1];
	cout<<ans<<endl;
	return 0;
}