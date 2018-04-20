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
	ll x;
	ll ans=0;
	
	cin>>x;
	ans = (x/11)*2;
	x%=11;
	//cerr<<x<<endl;
	if(x!=0)
	{
		if(x>6)
			ans+=2;
		else
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}