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
ll dp[100010];
int main()
{
	int n,m;
	ll ans=0;
	cin>>n>>m;
	fill(dp,dp+100010,0);

	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		dp[a]=-999;
	}
	dp[0]=1;
	//ここからDP
	for(int i=0;i<n+1;i++)
	{
		if(dp[i]>0)
		{
			if(dp[i+1]>=0)
			{
				dp[i+1]+=dp[i]+MOD;
				dp[i+1]%=MOD;
			}
			if(dp[i+2]>=0)
			{
				dp[i+2]+=dp[i]+MOD;
				dp[i+2]%=MOD;
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}