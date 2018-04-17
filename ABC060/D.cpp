#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll dp[101][301];
int w[101];
int v[101];

int main()
{
	int n,we;
	ll ans=0;
	
	cin>>n>>we;
	for(int i=1;i<n+1;i++)
	{
		cin>>w[i]>>v[i];
	}
	if(w[1]>3)
	{
		if(we<w[1])
		{
			cout<<0<<endl;
			return 0;
		}
		we %= w[1];
		for(int i=2;i<n+1;i++)
			w[i]-=w[1];
		w[1]=0;
	}

	//ここからDP
	fill(dp[0],dp[101],-1);
	dp[0][0]=0;
	for(int i=1;i<n+1;i++)
	{
		//cerr<<w[i]<<" "<<v[i]<<endl;
		for(int k=0;k<301;k++)
		{
			if(dp[i-1][k]>-1)
			{
				dp[i][k]=dp[i-1][k];
				if(k+w[i]<=we)
					dp[i][k+w[i]]=max(dp[i-1][k]+v[i],dp[i][k+w[i]]);
			}
		}
		cerr<<i<<endl;
		for(int j=0;j<we+1;j++)
			cerr<<dp[i][j]<<" ";
		cerr<<endl;
	}
	ans=-1;
	for(int i=0;i<we+1;i++)
	{
		//cerr<<dp[n][i]<<" ";
		if(ans<dp[n][i])
			ans=dp[n][i];
	}
	cout<<ans<<endl;
	return 0;
}