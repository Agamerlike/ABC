#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll extgcd(ll a, ll b,ll &x, ll &y)
{
	ll g=a;
	x=1;y=0;
	if(b!=0)
	{
		g=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	return g;
}

ll inv(ll a,ll m)
{
	ll x,y;
	if(extgcd(a,m,x,y)==1)
		return (x+m)%m;
	else
		return 0;
}

ll kai[200001];//mod 1e9+7での階乗
ll gyaku[200001]; //mod 1e9+7での階乗の逆元
int main()
{
	ll w,h;
	ll ans=0;
	cin>>w>>h;
	kai[0]=1;
	gyaku[0]=inv(kai[0],MOD);
	//階乗と逆元を求める
	for(int i=1;i<200001;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=MOD;
		if(kai[i]<0)
			kai[i]+=MOD;
		gyaku[i]=inv(kai[i],MOD);
	}

	//(w-1+h-1)C(w-1)を求める
	w--;h--;
	ans=kai[w+h]*gyaku[w];
	ans%=MOD;
	ans*=gyaku[h];
	ans=(ans+MOD)%MOD;
	
	cout<<ans<<endl;
	return 0;
}