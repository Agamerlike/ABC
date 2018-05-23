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
	int next;

	Edge(int n,int c)
	{
		next=n;
		cost=c;
	}
};

vector<Edge> g[100000];
bool used[100000];
ll mincost[100000];

ll x[100000];
ll y[100000];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	fill(used,used+100000,false);
	fill(mincost,mincost+100000,1e15);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			g[i].push_back(Edge(j,min(abs(x[i]-x[j]),abs(y[i]-y[j]))));
		}
	}

	//プリム
	mincost[0]=0;
	ll res=0;
	while(1)
	{
		int v=-1;
		for(int u=0;u<n;u++)
		{
			if(!used[u]&&(v==-1 || mincost[u]<mincost[v]))
				v=u;
		}
		if(v==-1)
			break;
		
		used[v]=true;
		res+=mincost[v];
		for(int u=0;u<n;u++)
		{
			ll t=1e15;
			for(int i=0;i<g[v].size();i++)
			{
				if(g[v][i].next==u)
					t=g[v][i].cost;
			}
			mincost[u]=min(mincost[u],t);
		}
	}

	cout<<res<<endl;
	return 0;
}