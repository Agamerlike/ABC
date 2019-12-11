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
ll a[100000];
ll ketacnt[64];
void ct(int i)
{
	ll tmp=a[i];
	for(ll k=0;k<62;k++)
	{
		if(tmp&(1LL<<k))
			ketacnt[k]++;
	}
	return;
}
int main()
{
	int n;
	ll ans=0;
	fill(ketacnt,ketacnt+64,0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ct(i);
	}
	for(int i=0;i<62;i++)
	{
		cerr<<ketacnt[i]<<endl;
		if(ketacnt[i]==0)
			continue;
		else if(ketacnt[i]&1)
			ans+=(1LL<<(ll)i);
		else
			ans+=(1LL<<(ll)(i+1));
	}
	cout<<ans<<endl;
	return 0;
}