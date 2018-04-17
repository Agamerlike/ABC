#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll t[200000];

int main()
{
	int n;
	ll s;
	int index=0;
	ll ans=0;
	
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
	}
	for(int i=0;i<n-1;i++)
	{
		ans += min(t[i+1]-t[i],s);
	}
	ans+=s;
	cout<<ans<<endl;
	return 0;
}