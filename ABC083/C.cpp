#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
	ll x,y;
	ll n;
	ll ans=0;
	
	cin>>x>>y;
	n=x;
	while(n<=y)
	{
		ans++;
		n*=2;
	}
	cout<<ans<<endl;
	return 0;
}