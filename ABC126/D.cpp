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

	Edge(int f,int t,ll c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

vector<Edge> g[100010];
int color[100010];

int dfs(int now)
{
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(color[e.to]!=-1)
			continue;
		
		if(e.cost%2==0)
		{
			color[e.to]=color[now];
			dfs(e.to);
		}else{
			color[e.to]=((color[now]+1)&1);
			dfs(e.to);
		}
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	fill(color,color+n+10,-1);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[u].push_back(Edge(v,w));
		g[v].push_back(Edge(u,w));
	}
	color[1]=0;
	dfs(1);
	for(int i=1;i<n+1;i++)
		cout<<color[i]<<endl;
	return 0;
}