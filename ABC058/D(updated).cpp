#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll x[100001];
ll y[100001];
ll xd[100001];
ll yd[100001];

int main()
{
	ll n,m;
	ll ans=0;
	ll xs=0;ll ys=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int i=0;i<m;i++)
		cin>>y[i];
	for(int i=1;i<n;i++)
		xd[i-1]=x[i]-x[i-1];
	for(int i=1;i<m;i++)
		yd[i-1]=y[i]-y[i-1];
	for(int i=0;i<n-1;i++)
	{
		ll tmp=0;
		tmp+=xd[i]*(ll)(i+1);
		tmp%=MOD;	
		tmp*=(ll)(n-1-i);
		tmp%=MOD;
		xs+=tmp;
		xs%=MOD;
	}
	for(int i=0;i<m-1;i++)
	{
		ll tmp=0;
		tmp+=yd[i]*(ll)(i+1);
		tmp%=MOD;
		tmp*=(ll)(m-1-i);
		tmp%=MOD;
		ys+=tmp;
		ys%=MOD;
	}
	ans=ys*xs;
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}