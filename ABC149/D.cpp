#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[100001][3];
map<char,int> m;
int main()
{
	int n,k;int pts[3];
	string t;
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<3;i++)
		cin>>pts[i];
	cin>>t;
	m['r']=0;
	m['s']=1;
	m['p']=2;
	fill(dp[0],dp[100001],0LL);
	//初期値の設定
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(j==(m[t[i]]+2)%3)
				dp[i][j]=pts[j];
		}
	}
	for(int i=0;i<k;i++)
	{
		int ind=i;
		for(int j=i+k;j<n;j+=k)
		{
			for(int l=0;l<3;l++)
			{
				ll pt=0;
				for(int s=0;s<3;s++)
				{
					if(l==s)
						continue;
					pt=max(pt,dp[j-k][s]);
				}
				if(l==(m[t[j]]+2)%3)
					dp[j][l]=max(dp[j][l],pt+pts[l]);
				else
					dp[j][l]=max(dp[j][l],pt);
			}
			ind+=k;
		}
		ll pt=0;
		for(int j=0;j<3;j++)
			pt=max(pt,dp[ind][j]);
		ans+=pt;
	}
	cout<<ans<<endl;
	return 0;
}