#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;
// bool operator<(P &lhs,P &rhs)
// {
// 	if(lhs.first==rhs.first)
// 		return lhs.second>rhs.second;
// 	else
// 		return lhs.first<rhs.first;
// }
int dp[3001][6001];
P ab[3000];
int main()
{
	int n,t;
	int ans=0;
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		ab[i]=P(a,b);
	}
	sort(ab,ab+n);
	fill(dp[0],dp[3001],-1);
	dp[0][0]=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<6001;j++)
		{
			if(dp[i-1][j]!=-1)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(j<t)
				{
					dp[i][j+ab[i-1].first]=max(dp[i][j+ab[i-1].first],dp[i-1][j+ab[i-1].first]);
					dp[i][j+ab[i-1].first]=max(dp[i][j+ab[i-1].first],dp[i-1][j]+ab[i-1].second);
				}
			}
		}
	}
	for(int i=0;i<6001;i++)
		ans=max(dp[n][i],ans);
	cout<<ans<<endl;
	return 0;
}