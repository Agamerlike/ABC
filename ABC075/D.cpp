#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n,k;
	int cnt=0;
	ll x[50];
	ll y[50];
	ll Mx;
	ll mx;
	ll My;
	ll my;
	ll ans=LLONG_MAX;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cnt=0;
			if(x[i]==x[j] || y[i]==y[j])
				continue;
			Mx = max(x[i],x[j]);
			mx = min(x[i],x[j]);
			My = max(y[i],y[j]);
			my = min(y[i],y[j]);
			for(int h=0;h<n;h++)
			{
				if(x[h]>=mx && x[h]<=Mx && y[h]>=my && y[h]<=My)
					cnt++;
			}
			if(cnt>=k)
				ans = min((Mx-mx)*(My-my),ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}