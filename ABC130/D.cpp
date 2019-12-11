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
ll rui[100005];

int main()
{
	int n;
	ll k;
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	fill(rui,rui+100005,-1000);
	rui[0]=0;
	for(int i=1;i<n+1;i++)
		rui[i]=rui[i-1]+a[i-1];
	
	int l=0;
	int r=1;
	ll s=0;
	bool f=true;
	cerr<<rui[n]<<endl;
	for(l=0;l<n;l++)
	{
		while(rui[r]-rui[l]<k)
		{
			if(r==n+1)
			{
				f=false;
				break;
			}
			//cerr<<l<<" "<<r<<" "<<rui[r]-rui[l]<<endl;
			r++;
		}
		if(!f)
			break;
		ans+=(ll)(n-(r-1));
	}
	cout<<ans<<endl;
	return 0;
}