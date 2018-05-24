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
	int n,k;
	ll ans=0;
	
	cin>>n>>k;
	ans = k;
	for(int i=0;i<n-1;i++)
	{
		ans*=(ll)(k-1);
	}
	cout<<ans<<endl;
	return 0;
}