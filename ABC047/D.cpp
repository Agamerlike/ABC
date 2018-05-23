#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100000];
ll diff[100000];//a[i]の差分
ll rui[100000];//diff[i]の和分

int main()
{
	int n;
	ll t;
	ll ans=0;
	ll m=0;//増加部分の最大値
	ll temp=0;
	ll lcnt=1;//rui[i]の最小値の個数
	ll l=0;//最小値
	ll rcnt=1;//rui[i]の最大値の個数
	ll r=0;//最大値
	
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>0)
			diff[i]=a[i]-a[i-1];
	}
	diff[0]=0;
	rui[0]=0;
	for(int i=1;i<n;i++)
	{
		rui[i]=rui[i-1]+diff[i];
		if(l>rui[i])
		{
			l=rui[i];
			lcnt=1;
		}else if(l==rui[i]){
			lcnt++;
		}
		if(r<rui[i])
		{
			r=rui[i];
			rcnt=1;
		}else if(r==rui[i]){
			rcnt++;
		}
	}

	ans=min(lcnt,rcnt);
	cout<<ans<<endl;
	return 0;
}