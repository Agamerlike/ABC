#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>> lnow;//lは小さい順に取り出したい
priority_queue<ll> rnow;//rは大きい順に取り出したい
ll a[300000];
ll lsum[300000];
ll rsum[300000];
int main()
{
	int n;
	ll ans=-1e16+1;
	cin>>n;
	for(int i=0;i<n*3;i++)
		cin>>a[i];
	lsum[n-1]=0;
	for(int i=0;i<n;i++)
	{
		lnow.push(a[i]);
		lsum[n-1]+=a[i];
	}
	//l側
	for(int i=n;i<2*n;i++)
	{
		ll tmp=lsum[i-1];
		//lは最大値
		if(a[i]>lnow.top())
		{
			tmp-=lnow.top();
			lnow.pop();
			lnow.push(a[i]);
			tmp+=a[i];
		}
		lsum[i]=tmp;
	}
	rsum[2*n]=0;
	for(int i=2*n;i<3*n;i++)
	{
		rnow.push(a[i]);
		rsum[2*n]+=a[i];
	}
	//r側
	for(int i=2*n-1;i>n-1;i--)
	{
		ll tmp=rsum[i+1];
		//rは最小値
		if(a[i]<rnow.top())
		{
			tmp-=rnow.top();
			rnow.pop();
			rnow.push(a[i]);
			tmp+=a[i];
		}
		rsum[i]=tmp;
	}
	for(int i=n-1;i<2*n;i++)
	{
		ans=max(ans,lsum[i]-rsum[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}