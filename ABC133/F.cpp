#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <deque>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
typedef pair<int,int> P;//depth,now
class Edge
{
	public:
	int cost;
	int color;
	int to;

	Edge(int n,int t,int c)
	{
		to=n;
		cost=t;
		color=c;
	}
};

vector<Edge> g[100000];
int root=0;
int parent[30][100000];
int depth[100000];
int dist[100000];//根までの距離
void dfs(int v,int p,int d)
{
	parent[0][v]=p;
	depth[v]=d;
	for(int i=0;i<g[v].size();i++)
	{
		Edge e=g[v][i];
		if(e.to!=p)
			dfs(e.to,v,d+1);
	}
}

void init(int t)
{
	dfs(root,-1,0);
	for(int k=0;k+1<30;k++)
	{
		for(int v=0;v<t;v++)
		{
			if(parent[k][v]<0)
				parent[k+1][v]=-1;
			else
				parent[k+1][v]=parent[k][parent[k][v]];
		}
	}
}

int lca(int u,int v)
{
	if(depth[u]>depth[v])
		swap(u,v);
	for(int k=0;k<30;k++)
	{
		if((depth[v]-depth[u])>>k&1)
			v=parent[k][v];
	}
	if(u==v)
		return u;
	
	for(int k=29;k>=0;k--)
	{
		if(parent[k][u]!=parent[k][v])
		{
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	return parent[0][u];
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n-1;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;b--;
		g[a].push_back(Edge(b,d,c));
		g[b].push_back(Edge(a,d,c));
	}
	for(int i=0;i<q;i++)
	{
		int x,y,u,v;
		cin>>x>>y>>u>>v;
		u--;v--;
	}
	return 0;
}