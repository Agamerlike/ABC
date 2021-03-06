#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;


ll a[300][300];//地図
ll d[300][300];//最短経路

int main()
{
	int n;
	ll ans=0;
	ll minus=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			d[i][j]=a[i][j];
			ans+=a[i][j];
		}
	}
	ans/=2;

	//ワーシャルフロイド
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}

	//地図が正しいかどうかのチェック
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]!=a[i][j])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}

	//省ける辺を探す
	//ワーシャルフロイド（変形）
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[i][j]==d[i][k]+d[k][j])
				{
					minus+=d[i][j];
				}
			}
		}
	}
	minus/=2;
	ans=ans-minus;
	
	cout<<ans<<endl;
	return 0;
}