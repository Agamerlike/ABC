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
int main()
{
	ll n;
	ll ans=0;
	cin>>n;
	if((n&1)||n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	ll tmp=10;
	while(tmp<=n)
	{
		ans+=(n/tmp);
		tmp*=5;
	}
	cout<<ans<<endl;
	return 0;
}