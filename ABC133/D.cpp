#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll a[100000];
ll ans[100000];
int main()
{
	int n;
	ll kei=0;
	ll mini=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		kei+=a[i];
		if((i&1)==0 && i!=n-1)
			mini+=a[i]*2;
	}
	ans[n-1]=kei-mini;
	ans[0]=a[n-1]*2-ans[n-1];
	for(int i=0;i<n-1;i++)
	{
		ans[i+1]=2*a[i]-ans[i];
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}