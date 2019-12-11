#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
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

//再帰で探す
ll saiki(int i,ll nowv,ll noww,ll mw)
{
	if(i==n)
		return nowv;
	ll maxv=0;
	if(noww+w[i]<=mw)
	{
		maxv=saiki(i+1,nowv+v[i],noww+w[i],mw);
	}
	return max(maxv,saiki(i+1,nowv,noww,mw));
}

int main()
{
	ll mw;//許容重量
	ll sumw=0;
	ll ans=0;
	int mode=-1;//0...data1 1...data2 2...data3
	cin>>n>>mw;
	if(n<=30)
		mode=0;
	bool fv=true;
	for(int i=0;i<n;i++)
	{
		cin>>v[i]>>w[i];
		sumw+=w[i];
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
	switch(mode)
	{
		case 0:
		if(sumw>mw)
			ans=saiki(0,0,0,mw);
		else{
			for(int i=0;i<n;i++)
				ans+=v[i];
		}
		//この再帰はコーナーケースでTLEする（原因不明）
		//以下bitで記述
		/*
		for(int bit=0;bit<1<<n;bit++)
		{
			//cerr<<bit<<endl;
			ll noww=0;ll nowv=0;
			ll tmp=bit;
			for(int j=0;j<n;j++)
			{
				int t=1<<j;
				if((tmp&t)>0)
				{
					noww+=w[j];
					nowv+=v[j];
				}
			}
			if(noww<=mw)
				ans=max(nowv,ans);
		}*/
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