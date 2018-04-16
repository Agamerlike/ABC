#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[300000];
ll lr[300000];

int main()
{
	int n;
	ll ans=-1*(1e15)-7;
	cin>>n;
	for(int i=0;i<3*n;i++)
		cin>>a[i];
	
	//境界点は右側に組み入れる
	for(int i=n;i<2*n+1;i++)
	{
		copy(a,a+(3*n),lr);
		sort(lr,lr+i);
		reverse(lr,lr+i);
		sort(lr+i,lr+3*n);
		reverse(lr+i,lr+3*n);
		ll lsum=0;
		ll rsum=0;
		/*
		for(int i=0;i<3*n;i++)
		{
			cerr<<lr[i]<<" ";
		}
		cerr<<endl;
		*/
		for(int i=0;i<n;i++)
		{
			lsum += lr[i];
			rsum += lr[(3*n-1)-i];
		}
		if(ans<lsum-rsum)
		{
			ans=lsum-rsum;
		}
	}
	cout<<ans<<endl;
	return 0;
}