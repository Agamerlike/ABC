#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll a[1000][1000];
ll dp[1000][1000];//dp[i][j]...(i,j)から何個繋げられるか
vector<pair<ll,pair<int,int>>> p;
int main()
{
	int h,w;
	ll ans=0;
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>a[i][j];
			p.push_back(make_pair(a[i][j],make_pair(i,j)));
		}
	}
	fill(dp[0],dp[1000],1);
	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	for(int i=0;i<p.size();i++)
	{
		int x=p[i].second.first;
		int y=p[i].second.second;
		//四方を順番に見る
		if(x>0 && a[x][y]<a[x-1][y])
			dp[x][y]+=dp[x-1][y];
		if(x<h-1 && a[x][y]<a[x+1][y])
			dp[x][y]+=dp[x+1][y];
		if(y>0 && a[x][y]<a[x][y-1])
			dp[x][y]+=dp[x][y-1];
		if(y<w-1 && a[x][y]<a[x][y+1])
			dp[x][y]+=dp[x][y+1];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			ans+=dp[i][j];
			ans=(ans+MOD)%MOD;
		}
	}
	while(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}