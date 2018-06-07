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
	ll n,k,x,y;
	ll ans=0;
	
	cin>>n>>k>>x>>y;
	ans=min(k,n)*x+max(n-k,0LL)*y;
	cout<<ans<<endl;
	return 0;
}