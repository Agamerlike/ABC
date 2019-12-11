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
ll ball[2005][2005]; //i個のボールをjグループに分ける分け方
ll kai[2005];
ll gyaku[2005];

ll beki(ll n,ll a)
{
	ll ret=1;
	ll k=n;
	while(a>0)
	{
		if(a&1)
		{
			ret*=k;
			ret%=MOD;
		}
		k=k*k;
		k%=MOD;
		a>>=1;
	}
	if(ret<0)
		ret+=MOD;
	return ret;
}

ll combi(int n,int k)
{
	ll ret=kai[n]*gyaku[k];
	ret%=MOD;
	ret*=gyaku[n-k];
	ret%=MOD;
	if(ret<0)
		ret+=MOD;
	return ret;
}

int main()
{
	int n,k;
	ll ans=0;
	cin>>n>>k;
	fill(ball[0],ball[2005],0);
	kai[0]=1;
	gyaku[0]=beki(1,MOD-2);
	for(int i=1;i<2005;i++)
	{
		kai[i]=kai[i-1]*(ll)i;
		kai[i]%=MOD;
		gyaku[i]=beki(kai[i],MOD-2);
	}
	for(int i=0;i<2005;i++)
	{
		for(int j=0;j<=i;j++)
			ball[i][j]=combi(i,j);
	}
	cerr<<ball[0][0]<<endl;
	cout<<n-(k-1)<<endl;
	for(int i=2;i<k+1;i++)
	{
		ll tmp=0;
		//間に入れる赤の数
		for(int j=i-1;j<=n-k;j++)
		{
			//塊はi*2-1個
			//赤の塊はi-1
			//青の塊はi
			//ボールはk+j個
			tmp=n-(k+j)+1; //塊自体の置き方
			tmp*=ball[k][i]; //青の分け方
			tmp%=MOD;
			tmp*=ball[j][i-1];//赤の分け方
			tmp%=MOD;
			ans+=tmp;
			ans%=MOD;
		}
		if(ans<0)
			ans+=MOD;
		cout<<ans<<endl;
	}
	return 0;
}