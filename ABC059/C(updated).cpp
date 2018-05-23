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
ll aa[100000];
ll sum[100000]; //a[i]までの和
int main()
{
	int n;
	ll ans=0;
	ll ans2=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		aa[i]=a[i];
	}
	
	//a[0]を+にする場合
	//初期化
	if(aa[0]<=0)
	{
		ans+=abs(1-aa[0]);
		aa[0]=1;
	}
	sum[0]=aa[0];
	for(int i=1;i<n;i++)
	{
		//sum[i]を-にする場合
		if(i%2==1)
		{
			if(aa[i]+sum[i-1]>=0)
			{
				ll temp=abs(-1-aa[i]-sum[i-1]);
				ans+=temp;
				aa[i]-=temp;
			}
		}else{
			//sum[i]を+にする場合
			if(aa[i]+sum[i-1]<=0)
			{
				ll temp=abs(1-aa[i]-sum[i-1]);
				ans+=temp;
				aa[i]+=temp;
			}
		}
		sum[i]=sum[i-1]+aa[i];
	}
	//ここまで
	//a[0]を-にする場合
	//初期化
	for(int i=0;i<n;i++)
		aa[i]=a[i];
	if(aa[0]>=0)
	{
		ans2+=abs(-1-aa[0]);
		aa[0]=-1;
	}
	sum[0]=aa[0];
	for(int i=1;i<n;i++)
	{
		//sum[i]を-にする場合
		if(i%2==0)
		{
			if(aa[i]+sum[i-1]>=0)
			{
				ll temp=abs(-1-aa[i]-sum[i-1]);
				ans2+=temp;
				aa[i]-=temp;
			}
		}else{
			//sum[i]を+にする場合
			if(aa[i]+sum[i-1]<=0)
			{
				ll temp=abs(1-aa[i]-sum[i-1]);
				ans2+=temp;
				aa[i]+=temp;
			}
		}
		sum[i]=sum[i-1]+aa[i];
	}
	cout<<min(ans,ans2)<<endl;
	return 0;
}