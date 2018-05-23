#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
typedef long long ll;

using namespace std;

class Edge
{
	public:
	int cost;
	int from;
	int to;

	Edge(int n,int c)
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


int d[100][100];
bool used[2000]; //使われてない辺:false 
vector<Edge> g;

int main()
{
	int n,m;
	int ans=0;
	cin>>n>>m;
	fill(d[0],d[100],(int)1e9-1);
	fill(used,used+2000,false);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		d[a][b]=c;
		d[b][a]=c;
		g.push_back(Edge(a,b,c));
		g.push_back(Edge(b,a,c));
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
	//それぞれの辺について使われているか確認する
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<g.size();k++)
		{
			Edge e = g[k];
			if(d[i][e.to]==d[i][e.from]+e.cost)
				used[k]=true;
		}
	}

	//使われてない辺を数える
	for(int i=0;i<2*m;i++)
	{
		if(!used[i])
			ans++;
	}
	ans/=2;
	cout<<ans<<endl;
	return 0;
}