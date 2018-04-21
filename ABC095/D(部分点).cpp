#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll x[100002];
ll v[100002];
ll rv[100001];//時計回り
ll lv[100001];//反時計回り

int main()
{
	int n;
	ll c;
	ll ans=0;
	ll ansr,ansl;
	ll man=0;
	ll rm;
	ll lm;
	
	cin>>n>>c;
	x[0]=0;
	v[0]=0;
	for(int i=1;i<n+1;i++)
	{
		cin>>x[i]>>v[i];
		ans+=v[i];
	}
	x[n+1]=c;
	v[n+1]=0;
	ans-=x[n-1];
	rv[0]=0;
	lv[0]=0;
	for(int i=1;i<n+1;i++)
	{
		rv[i]=rv[i-1]+v[i]-(x[i]-x[i-1]);
		lv[i]=lv[i-1]+v[n+1-i]-(x[n+2-i]-x[n+1-i]);
	}
	rm=0;
	lm=0;
	for(int i=1;i<n+1;i++)
	{
		if(rv[rm]<rv[i])
			rm=i;
		
		if(lv[lm]<lv[i])
			lm=i;
	}

	//時計回りに順番に調べる
	ansr=0;
	ansl=0;
	for(int i=1;i<n+1;i++)
	{
		ll temp = rv[i];
		man = temp;
		man-=x[i];
		for(int j=1;j<n+1-i;j++)
		{
			ll puk = man+lv[j];
			if(puk>temp)
				temp=puk;
		}
		if(temp>ansr)
			ansr=temp;
	}
	//反時計回り
	for(int i=1;i<n+1;i++)
	{
		ll temp=lv[i];
		man = temp;
		man-=(c-x[n+1-i]);
		for(int j=1;j<n+1-i;j++)
		{
			ll puk = man+rv[j];
			if(puk>temp)
				temp=puk;
		}
		if(temp>ansl)
			ansl=temp;
	}
	cerr<<ansl<<" "<<ansr<<endl;
	ans = max(ansr,ansl);
	cout<<ans<<endl;
	return 0;
}