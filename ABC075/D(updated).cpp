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

	for(int xi=0;xi<n;xi++)
	{
		for(int xj=xi+1;xj<n;xj++)
		{
			for(int yi=0;yi<n;yi++)
			{
				for(int yj=yi+1;yj<n;yj++)
				{
					cnt=0;
					Mx = max(x[xi],x[xj]);
					mx = min(x[xi],x[xj]);
					My = max(y[yi],y[yj]);
					my = min(y[yi],y[yj]);
					for(int h=0;h<n;h++)
					{
						if(x[h]>=mx && x[h]<=Mx && y[h]>=my && y[h]<=My)
							cnt++;
					}
					if(cnt>=k)
						ans=min((Mx-mx)*(My-my),ans);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}