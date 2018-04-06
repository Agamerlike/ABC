#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

class Edge
{
	public:
	int cost;
	int next;

	Edge(int n,int c)
	{
		next=n;
		cost=c;
	}
};

vector<Edge> g[100000];
ll depth[100000];
ll x[100000];
ll y[100000];

int dfs(int now,ll c)
{
	depth[now]=c;
	for(int i=0;i<g[now].size();i++)
	{
		//cerr<<"dfs"<<endl;
		Edge e=g[now][i];
		if(depth[e.next]==-1)
			dfs(e.next,c+e.cost);
	}
	return 0;
}

int main()
{
	int n,q,k;
	ll ans;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		g[a].push_back(Edge(b,c));
		g[b].push_back(Edge(a,c));
	}
	cin>>q>>k;
	k--;
	for(int i=0;i<q;i++)
	{
		//cerr<<"loop"<<endl;
		cin>>x[i]>>y[i];
		x[i]--;
		y[i]--;
	}
	fill(depth,depth+100000,-1);
	depth[k]=0;
	dfs(k,0);
	for(int i=0;i<q;i++)
	{
		ll xx=x[i];
		ll yy=y[i];
		ans = depth[xx]+depth[yy];
		cout<<ans<<endl;
	}
	return 0;
}