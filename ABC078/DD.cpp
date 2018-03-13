#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	ll z,w;
	ll a[2000];
	ll ans;
	
	cin>>n>>z>>w;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n>1)
	{
		ans = max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]));
	}else{
		ans = abs(a[0]-w);
	}
	cout<<ans<<endl;
	return 0;
}