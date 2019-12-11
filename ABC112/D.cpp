#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	ll n,m;
	ll ans=1;
	cin>>n>>m;
	
	ans=m/n;
	while(m%ans!=0)
		ans--;
	
	cout<<ans<<endl;
	return 0;
}