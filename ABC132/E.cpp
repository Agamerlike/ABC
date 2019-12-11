#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<int,int>> P;

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

vector<Edge> g[100000];

ll dp[100000][3];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(Edge(v,1));
	}
	int s,t;
	cin>>s>>t;
	s--;t--;
	fill(dp[0],dp[100000],1e8-1);
	dp[s][0]=0;
	priority_queue<P,vector<P>,greater<P>> q;
	q.push(P(dp[s][0],make_pair(s,0)));
	while(!q.empty())
	{
		P p=q.top();q.pop();
		if(p.first>dp[p.second.first][p.second.second])
			continue;
		for(int i=0;i<g[p.second.first].size();i++)
		{
			Edge e=g[p.second.first][i];
			int tmp=p.second.second+1;
				if(tmp==3)
					tmp=0;
			if(e.cost+dp[p.second.first][p.second.second]<dp[e.to][tmp])
			{
				dp[e.to][tmp]=e.cost+dp[p.second.first][p.second.second];
				q.push(P(dp[e.to][tmp],make_pair(e.to,tmp)));
			}
		}
	}
	if(dp[t][0]==1e8-1)
		cout<<-1<<endl;
	else
		cout<<dp[t][0]/3<<endl;
	return 0;
}