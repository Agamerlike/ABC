#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int g[50][50];
int route[50][2];

int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>route[i][0]>>route[i][1];
		route[i][0]--;
		route[i][1]--;
	}
	

	for(int i=0;i<m;i++)
	{
		//辺をひとつ除いたグラフの構成
		fill(g[0],g[50],100000);
		for(int j=0;j<m;j++)
		{
			if(j==i)
				continue;
			g[route[j][0]][route[j][1]]=1;
			g[route[j][1]][route[j][0]]=1;
		}

		//ワーシャルフロイド
		for(int k=0;k<n;k++)
		{
			for(int j=0;j<n;j++)
			{
				for(int l=0;l<n;l++)
				{
					g[j][l]=min(g[j][l],g[j][k]+g[k][l]);
				}
			}
		}

		//つながってない辺のチェック
		bool f=true;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(g[j][k]==100000)
				{
					f=false;
					break;
				}
			}
			if(!f)
				break;
		}
		if(!f)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}