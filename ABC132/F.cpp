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

ll kuri2(ll n,ll a)
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

ll ncnt[100000]; //n/i以上である個数
ll dp[101][100000];
int main()
{
	ll n;
	int k;
	ll ans=0;
	cin>>n>>k;
	ll sqn=sqrt(n);
	ll bign=n-sqn;
	for(int i=1;i<100000;i++)
	{
		if(n%i==0)
			ncnt[i]=n/i-sqn;
		else
			ncnt[i]=n/i+1-sqn;
	}
	ans=kuri2(sqn,k); //なんでもいける列
	fill(dp[0],dp[101],0);
	for(int i=1;i<sqn+1;i++)
		dp[1][i]=1;
	for(int i=2;i<k+1;i++)
	{
		
	}
	cout<<ans<<endl;
	return 0;
}