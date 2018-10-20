#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

class Edge
{
	public:
	ll cost;
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

vector<Edge> g[100000];
vector<Edge> r[100000];//逆辺（逆向きに張る辺）
ll in[100000];//滞在することで得られる報酬
ll d[100000];//行きにかかる時間
ll rd[100000];//帰りにかかる時間

int main()
{
	int n,m;
	ll t;
	ll ans=0;
	cin>>n>>m>>t;
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		g[a].push_back(Edge(b,c));
		r[b].push_back(Edge(a,c));
	}

	//ここからダイクストラ（行き）
	priority_queue<P,vector<P>,greater<P>> que;
	fill(d,d+n,1e17-1);
	d[0]=0;
	que.push(P(0,0));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		if(p.first>d[p.second])
			continue;
		
		for(int i=0;i<g[p.second].size();i++)
		{
			Edge e=g[p.second][i];
			if(d[e.to]>d[p.second]+e.cost)
			{
				d[e.to]=d[p.second]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	//ここまでダイクストラ
	//ここからダイクストラ（帰り）
	fill(rd,rd+n,1e17-1);
	rd[0]=0;
	que.push(P(0,0));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		if(p.first>rd[p.second])
			continue;
		
		for(int i=0;i<r[p.second].size();i++)
		{
			Edge e=r[p.second][i];
			if(rd[e.to]>rd[p.second]+e.cost)
			{
				rd[e.to]=rd[p.second]+e.cost;
				que.push(P(rd[e.to],e.to));
			}
		}
	}
	//ここまでダイクストラ

	for(int i=0;i<n;i++)
	{
		//cerr<<d[i]<<" "<<rd[i]<<endl;
		if(d[i]==1e17-1 || rd[i]==1e17-1)
			continue;
		
		ll tmp=in[i]*(t-d[i]-rd[i]);
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}