#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
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
class Cycle
{
	public:
	int size;
	vector<int> node;
	Cycle(){}
	Cycle(int s,vector<int> n)
	{
		size=s;node=n;
	}
	bool operator<(Cycle &rhs)
	{
		return size<rhs.size;
	}
};
typedef vector<vector<Edge>> Graph;
Graph g;
vector<Cycle> res;
void bfs(int now)
{
	deque<Cycle> que;
	que.push_back(Cycle(1,vector<int>(1,now)));
	Cycle c;
	int cnt=0;
	bool f=false;
	while(!que.empty())
	{
		cnt++;
		if(cnt>1000)
			break;
		c=que[0];
		que.pop_front();
		//cerr<<now<<" "<<c.size<<" "<<c.node[c.node.size()-1]<<endl;
		vector<int> r=c.node;
		for(int i=0;i<g[c.node[c.node.size()-1]].size();i++)
		{
			Edge e=g[c.node[c.node.size()-1]][i];
			if(e.to==c.node[0])
			{
				f=true;
				break;
			}
			r=c.node;
			r.push_back(e.to);
			que.push_back(Cycle(c.size+1,r));
		}
		if(f)
			break;
	}
	if(f)
		res.push_back(c);
	return;
}
int main()
{
	int n,m;
	cin>>n>>m;
	g=Graph(n);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
	}
	//各頂点を始点とする最小サイクルを探す
	for(int i=0;i<n;i++)
	{
		bfs(i);
	}
	if(res.size()==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(res.begin(),res.end());
	cout<<res[0].size<<endl;
	for(int i=0;i<res[0].node.size();i++)
		cout<<res[0].node[i]+1<<endl;
	return 0;
}