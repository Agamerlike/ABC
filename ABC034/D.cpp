#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
ll MOD = 1e9+7;

pair<double,double> dp[1001][1001];//i番目まででk個選んだときにできる食塩水の濃度と量の最大値
pair<double,double> en[1001];
int main()
{
	int n,k;
	double ans=0;
	cin>>n>>k;
	for(int i=1;i<n+1;i++)
	{
		double w;
		double p;
		cin>>w>>p;
		p/=100.0f;
		en[i]=P(p,w);
	}
	fill(dp[0],dp[1001],P(-1.0f,-1.0f));
	//ここからdp
	dp[0][0]=P(0.0f,0.0f);
	for(int i=1;i<n+1;i++)
	{
		//dp[i-1][j]を調べる
		for(int j=0;j<1001;j++)
		{
			//チェックは誤差のないsecondでする
			if(dp[i-1][j]!=P(-1.0f,-1.0f))
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				//i番目を加える場合濃度を求める
				double pp=en[i].first*en[i].second+dp[i-1][j].first*dp[i-1][j].second;//塩の量
				pp=pp/(en[i].second+dp[i-1][j].second);//濃度
				dp[i][j+1]=max(dp[i][j+1],P(pp,en[i].second+dp[i-1][j].second));
			}
		}
	}
	for(int i=1;i<n+1;i++)
		cerr<<en[i].first<<" "<<en[i].second<<endl;
	for(int i=0;i<k+1;i++)
		cerr<<dp[n][i].first<<" "<<dp[n][i].second<<endl;
	//ここまでDP
	//k個選んだときの最大値dp[n][k]が答え
	ans=dp[n][k].first*100;
	cout<<fixed<<ans<<endl;
	return 0;
}