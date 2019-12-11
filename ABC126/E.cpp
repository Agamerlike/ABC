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
bool used[100010];

int dfs(int now)
{
	used[now]=true;
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(used[e.to])
			continue;
		dfs(e.to);
	}
	return 0;
}

int main()
{
	int n,m;
	ll ans=0;
	cin>>n>>m;
	fill(used,used+n+10,false);
	for(int i=0;i<m;i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[u].push_back(Edge(v,w));
		g[v].push_back(Edge(u,w));
	}
	used[0]=true;
	for(int i=1;i<n+1;i++)
	{
		if(!used[i])
		{
			ans++;
			dfs(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}