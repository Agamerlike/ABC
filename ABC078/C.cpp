#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n,m;
	ll x,y;
	ll ans=0;
	
	cin>>n>>m;
	x = m*1900+(n-m)*100;
	y = pow(2,m);
	ans = x*y;
	cout<<ans<<endl;
	return 0;
}