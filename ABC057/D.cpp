#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

double dp[51][51];
ll v[51];

int main()
{
	int n,a,b;
	double mm=-1;
	int cnt=0;
	
	cin>>n>>a>>b;
	for(int i=1;i<n+1;i++)
		cin>>v[i];
	fill(dp[0],dp[51],-1);
	dp[0][0]=0;

	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			if(dp[i-1][j]!=-1)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j]);
				dp[i][j+1]=max((dp[i-1][j]+(double)v[i])/(double)(j+1),dp[i][j+1]);
			}
		}
	}
	
	for(int i=a;i<b+1;i++)
	{
		if(dp[50][i]>mm)
		{
			mm=dp[50][i];
			cnt=1;
		}else if(dp[50][i]==mm){
			cnt++;
		}
	}

	return cnt;
	return 0;
}