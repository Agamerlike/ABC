#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;

class Edge
{
	public:
	ll cost;
	int from;
	int to;

	Edge(int n,ll c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

vector<Edge> g[2500];
ll dist[2500];
bool negative[2500];//negative loopから到達できる頂点のチェック
//negative loopから到達できる頂点の検出
void saiki(int now)
{
	if(!negative[now])
		return;
	for(int i=0;i<g[now].size();i++)
	{
		if(!negative[g[now][i].to])
		{
			negative[g[now][i].to]=true;
			saiki(g[now][i].to);
		}
	}
	return;
}
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=0;i<m;i++)
	{
		int a,b;
		ll c;
		cin>>a>>b>>c;
		c-=p;a--;b--;
		g[a].push_back(Edge(b,-c));
	}
	//ベルマンフォード
	//始点から到達できるnegative loopも検出する
	fill(dist,dist+2500,1e14-1);
	fill(negative,negative+2500,false);
	dist[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<g[j].size();k++)
			{
				Edge e=g[j][k];
				if(dist[j]!=1e14-1 && dist[e.to]>dist[j]+e.cost)
				{
					dist[e.to]=dist[j]+e.cost;
					if(i==n-1)
					{
						negative[j]=true;
						negative[e.to]=true;
					}
				}
			}
		}
	}
	//negative loopのチェック
	for(int i=0;i<n;i++)
		saiki(i);
	if(negative[n-1])
		cout<<-1<<endl;
	else
		cout<<max(-dist[n-1],0LL)<<endl;
	return 0;
}