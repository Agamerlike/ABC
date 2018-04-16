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
	ll cost;
	int next;

	Edge(int n,ll c)
	{
		next=n;
		cost=c;
	}
};

vector<Edge> g[1000];
bool negative[1000];
ll d[1000];
ll inf = 1e15+7;

int main()
{
	int n,m;
	ll ans;
	bool f=false;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		ll c;
		cin>>a>>b>>c;
		a--;
		b--;
		c*=-1;
		g[a].push_back(Edge(b,c));
	}
	fill(d,d+1000,inf);
	d[0]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<g[j].size();k++)
			{
				Edge e =g[j][k];
				if(d[j]!=inf && d[e.next]>d[j]+e.cost)
				{
					d[e.next]=d[j]+e.cost;
				}
			}
		}
	}
	ans = d[n-1];
	//negative loop
	fill(negative,negative+1000,false);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<g[j].size();k++)
			{
				Edge e = g[j][k];
				if(d[j]!=inf && d[e.next]>d[j]+e.cost)
				{
					d[e.next]=d[j]+e.cost;
					negative[e.next]=true;
				}

				if(negative[j])
					negative[e.next]=true;
			}
		}
	}
	if(negative[n-1])
		cout<<"inf"<<endl;
	else
		cout<<-1*ans<<endl;
	return 0;
}