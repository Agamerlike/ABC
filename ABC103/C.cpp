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
	int n;
	ll a[100000];
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans+=(a[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}