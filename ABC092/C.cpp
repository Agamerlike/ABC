#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int a[100002];
int r[100002];
int k[100002];

int main()
{
	int n;
	ll ans=0;
	a[0]=0;
	r[0]=0;
	
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		int temp;
		cin>>a[i];
		r[i]=r[i-1]+abs(a[i]-a[i-1]);
	}
	a[n+1]=0;
	r[n+1]=r[n]+abs(0-a[n]);

	for(int i=1;i<n+1;i++)
	{
		k[i]=abs(a[i+1]-a[i-1]);
	}

	for(int i=1;i<n+1;i++)
	{
		ans=0;
		ans += r[i-1];
		ans += (r[n+1]-r[i+1]);
		ans += k[i];
		cout<<ans<<endl;
	}
	return 0;
}