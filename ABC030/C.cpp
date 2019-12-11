#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll a[100000];
ll b[100000];

int main()
{
	int n,m;
	ll x,y;
	int ans=0;
	cin>>n>>m;
	cin>>x>>y;
	fill(a,a+100000,-1);
	fill(b,b+100000,-1);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<m;i++)
		cin>>b[i];
	ll now=0;

	while(1)
	{
		if(ans%2==0)
		{
			auto itr = lower_bound(a,a+n,now);
			//終了条件
			if((*itr)<now)
				break;
			
			now=(*itr)+x;
			cerr<<(*itr)<<" "<<now<<endl;
			ans++;
		}else{
			auto itr = lower_bound(b,b+m,now);
			//終了条件
			if((*itr)<now)
				break;
			
			now=(*itr)+y;
			cerr<<(*itr)<<" "<<now<<endl;
			ans++;
		}
	}
	ans/=2;
	cout<<ans<<endl;
	return 0;
}