#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll dp[51][5001];//dp[i][j+2500]...i番目までの取った数字の和がjになるような組み合わせの数

int main()
{
	int n;
	ll a;
	ll x[51];
	ll ans=0;
	
	cin>>n>>a;
	for(int i=0;i<n;i++)
	{
		cin>>x[i+1];
		x[i+1]-=a;
	}
	
	//初期化
	fill(dp[0],dp[51],0);
	dp[0][2500]=1;
	//ここからdp
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<5001;j++)
		{
			dp[i][j]=dp[i-1][j]; //上書き
		}
		for(int j=0;j<5001;j++)
		{
			if(j+x[i]>-1 && j+x[i]<5001)
				dp[i][j+x[i]]+=dp[i-1][j];
		}
	}
	ans=dp[n][2500]-1;
	cout<<ans<<endl;
	return 0;
}