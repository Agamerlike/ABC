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
ll dp[2004][2004];
ll rui[2004][2004];
int s[2000];
int t[2000];
int main()
{
	int n,m;
	ll ans=0;
	cin>>n>>m;
	fill(dp[0],dp[2004],0);
	fill(rui[0],rui[2004],0);
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int j=0;j<m;j++)
		cin>>t[j];
	dp[0][0]=1;
	for(int i=1;i<m+1;i++)
		dp[0][i]=1;
	for(int i=1;i<n+1;i++)
		dp[i][0]=1;
	// start dp
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			if(s[i-1]!=t[j-1])
				dp[i][j]-=dp[i-1][j-1];
			dp[i][j]%=MOD;
		}
	}
	//end dp
	ans=dp[n][m];
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}