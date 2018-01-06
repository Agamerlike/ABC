#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,ma,mb;
	int a[40];
	int b[40];
	int c[40];
	int dp[41][401][401];
	int amax=0;
	int bmax=0;
	int ans = 10000;
	bool flag = false;
	for(int i=0;i<41;i++)
	{
		for(int j=0;j<401;j++)
		{
			for(int k=0;k<401;k++)
			{
				dp[i][j][k]=10000;
			}
		}
	}
	cin>>n>>ma>>mb;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	
	//ここからDP
	//何も使わない調合
	for(int i=0;i<n+1;i++)
	{
		dp[i][0][0]=0;
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<amax+1;j++)
		{
			for(int k=0;k<bmax+1;k++)
			{
				dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);//薬を加えない場合
				dp[i][j+a[i-1]][k+b[i-1]] = min(dp[i-1][j+a[i-1]][k+b[i-1]],dp[i-1][j][k]+c[i-1]); //薬を加える場合
			}
		}
		amax+=a[i-1];
		bmax+=b[i-1];
	}
	//ここまでDP
	for(int i=0;i<amax+1;i++)
	{
		for(int j=0;j<bmax+1;j++)
		{
			cerr<<dp[n][i][j]<<" ";
		}
		cerr << endl;
	}
	//答えを求める
	for(int i=1;i<(400/max(ma,mb))+1;i++)
	{
		if(dp[n][ma*i][mb*i]<ans)
		{
			flag=true;
			ans=dp[n][ma*i][mb*i];
		}
	}
	if(flag==false)
	{
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}
