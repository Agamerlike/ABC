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
	ll a,b,x;
	ll ans=0;
	
	cin>>a>>b>>x;
	ans = (b/x+1);
	if(a!=0)
		ans-=(a-1)/x+1;
	cout<<ans<<endl;
	return 0;
}