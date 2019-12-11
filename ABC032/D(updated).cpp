#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <typeinfo>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int n;
ll v[200];
ll w[200];
ll dp[201][200001];//i番目までの荷物で重さもしくは価値jで最大（最小）の価値（重さ）

//w[]の要素をjとしてナップザックする (mode1)
void solveknap1(int mode,ll mw)
{
	fill(dp[0],dp[201],-1000);
	dp[0][0]=0;
	ll mm=0;//現段階で考えられる最大価値（重さ）
	//ここからdp
	for(int i=0;i<n;i++)
	{
		for(ll j=0;j<mm+1;j++)
		{
			if(dp[i][j]!=-1000)
			{
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);//価値の場合は最大化
				dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);//価値の場合は最大化
				mm=max(mm,j+w[i]);
			}
		}
	}
	//ここまでdp
}

//v[]の要素をjとしてdp(mode2)
void solveknap2(int mode,ll mw)
{
	fill(dp[0],dp[201],1e14-1);
	dp[0][0]=0;
	ll mm=0;//現段階で考えられる最大価値（重さ）
	//ここからdp
	for(int i=0;i<n;i++)
	{
		for(ll j=0;j<mm+1;j++)
		{
			if(dp[i][j]!=1e14-1)
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);//重さの場合は最小化
				dp[i+1][j+v[i]]=min(dp[i+1][j+v[i]],dp[i][j]+w[i]);//重さの場合は最小化
				mm=max(j+v[i],mm);
			}
		}
	}
	//ここまでdp
}

//半分全列挙
//[l,r)についてすべての取りうる要素を列挙する
vector<pair<ll,ll>> rekkyo(int l,int r,ll mw)
{
	vector<pair<ll,ll>> ret;
	int cnt=r-l;
	for(ll bit=0;bit<(ll)pow(2,cnt);bit++)
	{
		auto ele=make_pair(0LL,0LL);
		ll tmp=bit;
		for(int i=0;i<cnt;i++)
		{
			if((tmp&(ll)pow(2,i))>0)
			{
				ele.first+=w[l+i];
				ele.second+=v[l+i];
			}
		}
		if(ele.first<=mw)
			ret.push_back(ele);
	}
	return ret;
}

int main()
{
	ll mw;//許容重量
	ll ans=0;
	int mode=-1;//0...data1 1...data2 2...data3
	cin>>n>>mw;
	if(n<=30)
		mode=0;
	bool fv=true;
	for(int i=0;i<n;i++)
	{
		cin>>v[i]>>w[i];
		if(v[i]>1000)
			fv=false;
	}
	if(mode==-1)
	{
		if(fv)
			mode=2;
		else
			mode=1;
	}
	//mode=2;
	//cerr<<mode<<endl;
	//ここからsolve
	vector<pair<ll,ll>> l;
	vector<pair<ll,ll>> r;
	ll m=0;
	switch(mode)
	{
		case 0:
		l=rekkyo(0,n/2,mw);
		r=rekkyo(n/2,n,mw);
		sort(r.begin(),r.end());
		for(auto itr=r.begin();itr!=r.end();++itr)
		{
			m=max((*itr).second,m);
			(*itr).second=m;
		}
		for(int i=0;i<l.size();i++)
		{
			auto itr = lower_bound(r.begin(),r.end(),make_pair(mw-l[i].first,(ll)1e18));//lの要素と合わせるとギリギリmwを上回ってしまうrの要素を探す
			if(itr!=r.begin())
				itr--;//1つ前が答え
			
			if((*itr).first+l[i].first<=mw)
			{
				ans=max(ans,(*itr).second+l[i].second);
			}
		}
		break;
		case 1:
		solveknap1(mode,mw);
		for(int i=0;i<min(200001,(int)mw+1);i++)
		{
			ans=max(ans,dp[n][i]);
		}
		break;
		case 2:
		solveknap2(mode,mw);
		for(int i=0;i<200001;i++)
		{
			if(dp[n][i]<=mw)
				ans=i;
		}
		break;
	}
	//ここまでsolve
	cout<<ans<<endl;
	return 0;
}