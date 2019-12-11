#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
ll h[301];
ll dp[301][301];//一番右端がi,削除していない列の数がj
//dp[i][j]の更新
void calc(int i,int j)
{
	//その前に生き残った行を全探索
	if(j>0)
	{
		for(int a=0;a<i;a++)
			dp[i][j]=min(dp[i][j],dp[a][j-1]+max(0LL,h[i]-h[a]));
	}else if(i==0){
		dp[i][j]=0;
	}
}
int main()
{
	int n,k;
	ll ans=1e14-1;
	cin>>n>>k;
	h[0]=0;
	for(int i=1;i<n+1;i++)
	{
		cin>>h[i];
	}
	fill(dp[0],dp[301],1e14-1);
	dp[0][0]=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<i+1;j++)
			calc(i,j);
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=n-k;j<n+1;j++)
		{
			//cerr<<dp[i][j]<<" ";
			ans=min(ans,dp[i][j]);
		}
		//cerr<<endl;
	}
	cout<<ans<<endl;
	return 0;
}