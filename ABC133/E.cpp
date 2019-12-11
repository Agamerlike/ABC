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
ll used[100000];
deque<P> q;

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	fill(used,used+100000,-1e14+1);
	used[0]=k;//init
	q.push_back(P(0,0));
	while(!q.empty())
	{
		P p=q[0];
		q.pop_front();
		int now=p.second;
		int nowk=max(k-p.first-1,k-2);
		for(int i=0;i<g[now].size();i++)
		{
			Edge e=g[now][i];
			if(used[e.to]==-1e14+1)
			{
				used[e.to]=nowk;
				q.push_back(P(p.first+1,e.to));
				nowk--;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(used[i]<0)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	ll ans=1;
	for(int i=0;i<n;i++)
	{
		ans*=used[i];
		ans%=MOD;
	}
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}