#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll kai[2000001];
ll gyaku[2000001];
ll kuri2(ll x,ll a)
{
	ll ret=1;
	ll tmp=x;
	while(a>0)
	{
		if(a&1)
		{
			ret*=tmp;
			ret%=MOD;
		}
		a>>=1;
		tmp*=tmp;
		tmp%=MOD;
	}
	if(ret<0)
		ret+=MOD;
	return ret;
}
int main()
{
	int x,y;
	int p,m,a,b;
	ll ans=0;
	cin>>x>>y;
	kai[0]=1;
	gyaku[0]=kuri2(kai[0],MOD-2);
	for(ll i=1;i<2000001;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=MOD;
		if(kai[i]<0)
			kai[i]+=MOD;
		gyaku[i]=kuri2(kai[i],MOD-2);
	}
	if((x+y)%3!=0)
	{
		cout<<0<<endl;
		return 0;
	}
	p=(x+y)/3;
	m=x-y;
	a=(p+m)/2;
	b=(p-m)/2;
	if(!(a+b==p && a>=0 && b>=0))
	{
		cout<<0<<endl;
		return 0;
	}
	ans=kai[p]*gyaku[a];
	ans%=MOD;
	ans*=gyaku[p-a];
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}