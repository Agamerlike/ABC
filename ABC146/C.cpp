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
ll keta(ll x)
{
	ll ret=0;
	while(x>0)
	{
		ret++;
		x/=10;
	}
	return ret;
}
int main()
{
	ll a,b,x;
	ll ans=0;
	cin>>a>>b>>x;
	ll ok=0;ll ng=1e9+1;
	while(ng-ok>1)
	{
		ll mid=(ok+ng)/2;
		if(mid*a+keta(mid)*b>x)
			ng=mid;
		else
			ok=mid;
	}
	cout<<ok<<endl;
	return 0;
}