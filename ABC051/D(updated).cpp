#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

int d[100][100];
P mp[100][100];
bool used[2000];
int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;
	fill(d[0],d[100],1e8-1);
	fill(mp[0],mp[100],P(1e8-1,1e8-1));
	fill(used,used+2000,false);
	for(int i=0;i<n;i++)
		d[i][i]=0;
	fill(used,used+2000,false);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		d[a][b]=c;
		d[b][a]=c;
		mp[a][b]=P(c,i);
		mp[b][a]=P(c,i);
	}

	//ワーシャルフロイド
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	//ワーシャルフロイドここまで
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//cerr<<i<<" "<<j<<endl;
			//ij間の最短経路を調べる
			if(mp[i][j].first!=1e8-1 && mp[i][j].first>d[i][j])
				used[mp[i][j].second]=true;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(used[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}