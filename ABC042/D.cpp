#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll kai[200001];

ll extgcd(ll a,ll b,ll &x,ll &y)
{
	ll d=a;
	if(b!=0)
	{
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;
		y=0;
	}
	return d;
}

ll inver(ll a)
{
	ll x,y;
	extgcd(a,MOD,x,y);
	return (MOD+x%MOD)%MOD;
}

ll combi(ll a,ll b)
{
	ll ret=kai[a];
	ret*=inver(kai[b]);
	ret%=MOD;
	ret*=inver(kai[a-b]);
	ret%=MOD;
	if(ret<0)
		ret+=MOD;
	return ret;
}

int main()
{
	ll h,w,a,b;
	ll ans=0;
	
	cin>>h>>w>>a>>b;
	kai[0]=1;
	for(int i=1;i<200001;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=MOD;
		if(kai[i]<0)
			kai[i]+=MOD;
	}
	
	for(ll i=0;i<h-a;i++)
	{
		ll temp=combi(b-1+i,i)*combi(w-b-1+h-i-1,w-b-1);
		temp%=MOD;
		if(temp<0)
			temp+=MOD;
		ans+=temp;
		ans%=MOD;
		if(ans<0)
			ans+=MOD;
	}
	cout<<ans<<endl;
	return 0;
}