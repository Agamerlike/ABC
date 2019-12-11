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
int a[80][80];
int b[80][80];
int c[80][80];
bool dp[80][80][25601];
int main()
{
	int h,w;
	int ans=1e8-1;
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cin>>b[i][j];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			c[i][j]=a[i][j]-b[i][j];
	}
	fill(dp[0][0],dp[80][0],false);
	dp[0][0][12800+c[0][0]]=true;
	dp[0][0][12800-c[0][0]]=true;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			for(int k=0;k<25601;k++)
			{
				if(dp[i][j][k])
				{
					if(i!=h-1)
					{
						dp[i+1][j][k+c[i+1][j]]=true;
						dp[i+1][j][k-c[i+1][j]]=true;
					}
					if(j!=w-1)
					{
						dp[i][j+1][k+c[i][j+1]]=true;
						dp[i][j+1][k-c[i][j+1]]=true;
					}
				}
			}
		}
	}
	for(int k=0;k<25601;k++)
	{
		if(dp[h-1][w-1][k])
		{
			//cerr<<k-12800<<endl;
			ans=min(ans,abs(k-12800));
		}
	}
	cout<<ans<<endl;
	return 0;
}