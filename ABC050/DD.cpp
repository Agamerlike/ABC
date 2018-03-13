#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n;
	ll ans=0;
	ll cnt;
	
	cin>>n;
	//xorを基準に調べる
	for(ll u=0;u<n+1;u++)
	{
		//sumは
		//a+b = (a xor b)+(a and b)*2というように表せる
		//したがってu以上n以下の数をkとするとk-uが偶数となるようなものにはvが存在
		ans += (n-u)/2;
		cnt = (n-u)/2;
		//cerr<<u<<" "<<cnt<<endl;
		ans%=MOD;
	}
	ans += n;
	ans %= MOD;
	cout<<ans<<endl;
	return 0;
}