#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[200000];
ll b[200000];
ll xor1[200000];
int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}

	for(int i=0;i<n;i++)
	{
		xor1[i]=(a[i]^b[i]);
	}
	for(int i=1;i<n;i++)
	{
		xor1[i]=(xor1[i-1]^xor1[i]);
	}
	ans=xor1[n-1];
	cout<<ans<<endl;
	return 0;
}