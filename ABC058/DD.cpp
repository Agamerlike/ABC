#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll x[100000];
ll y[100000];

int main()
{
	int n,m;
	ll ans=0;

	ll a=0;
	ll b=0;
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int i=0;i<m;i++)
		cin>>y[i];
	
	for(int i=0;i<n;i++)
	{
		a+=x[i]*i;
		a-=x[i]*(n-1-i);
	}
	a%=MOD;
	for(int i=0;i<m;i++)
	{
		b+=y[i]*i;
		b-=y[i]*(n-1-i);
	}
	b%=MOD;
	ans = a*b;
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}