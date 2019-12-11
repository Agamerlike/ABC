#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
ll dp[101][5][5][5];//現在の文字からさかのぼってj,kだった場合にi文字目に来れる文字の数
bool m[101][5][5][5];
//null...0 A...1 C...2 G...3 T...4
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	//fill(dp[0][0][0],dp[101][5][5],0);
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				for(int l=0;l<5;l++)
					m[i][j][k][l]=false;
			}
		}
	}	

	dp[1][1][0][0]=1;
	dp[1][2][0][0]=1;
	dp[1][3][0][0]=1;
	dp[1][4][0][0]=1;
	//ここからDP
	for(int i=2;i<n+1;i++)
	{
		for(int j=1;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				for(int l=0;l<5;l++)
				{
					if(dp[i-1][j][k][l]>0)
					{
						for(int a=1;a<5;a++)
						{
							dp[i][a][j][k]+=dp[i-1][j][k][l];
							//dp[i][a][j][k]%=MOD;
						}
						
						//AG?Cの場合を取り除く
						if(k==3 && l==1 && !m[i-1][0][k][l])
						{
							m[i-1][0][k][l]=true;
							for(int a=1;a<5;a++)
								dp[i][2][a][k]-=dp[i-1][a][k][l];
						}
						//A?GC
						if(l==1 && j==3 && !m[i-1][j][0][l])
						{
							m[i-1][j][0][l]=true;
							for(int a=1;a<5;a++)
								dp[i][2][j][a]-=dp[i-1][j][a][l];
						}
						//AGGCの場合を足す
						if(l==1 && j==3 && k==3 && !m[i-1][j][k][l])
						{
							m[i-1][j][k][l]=true;
							dp[i][2][j][k]+=dp[i-1][j][k][l];
						}
						for(int a=1;a<5;a++)
							dp[i][a][j][k]%=MOD;
						
						dp[i][3][2][1]=0;
						dp[i][2][1][3]=0;
						dp[i][2][3][1]=0;
					}
				}
			}
		}
	}
	//ここまでDP
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				//cerr<<i<<" "<<j<<" "<<k<<" "<<dp[n][i][j][k]<<endl;
				ans+=dp[n][i][j][k];
				ans%=MOD;
			}
		}
	}
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}