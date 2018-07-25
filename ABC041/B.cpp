#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	ll a,b,c;
	ll ans=0;
	
	cin>>a>>b>>c;
	ans=a*b;
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	ans*=c;
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}