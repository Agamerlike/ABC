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
	ll cap;
	int next;
	int rev;

	Edge(int n,ll c,int r)
	{
		next=n;
		cap=c;
		rev=r;
	}
};

vector<Edge> g[202];
bool used[202];

//増加パスをdfsで探す
//now...現在の頂点
//goal...目標の頂点
//nowflow...現在の流量
ll dfs(int now,int goal,ll nowflow)
{
	if(now==goal)
		return nowflow; //goalまで到達できればとりあえず流せている
	used[now]=true;
	for(int i=0;i<g[now].size();i++)
	{
		Edge &e = g[now][i];
		//使われていないかつ流せる頂点を探す
		if(!used[e.next] && e.cap>0)
		{
			ll d = dfs(e.next,goal,min(nowflow,e.cap)); //流せる限り流したシミュレーションを行う
			if(d>0)
			{
				e.cap -= d; //流せていたら流量の分容量を差し引く
				g[e.next][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

//辺と逆辺を張る
int adde(int from,int to, int cap)
{
	g[from].push_back(Edge(to,cap,g[to].size()));
	g[to].push_back(Edge(from,0,g[from].size()-1));//逆辺
	return 0;
}

int main()
{
	int n;
	pair<int,int> r[100];
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i].first>>r[i].second;
	}
	//ここからグラフ作る
	//s->赤->青->tの順番で流すことを考える
	//s...0
	//t...2*n
	for(int i=0;i<n;i++)
	{
		adde(0,i+1,1);
		adde(n+1+i,2*n+1,1);
	}
	sort(r,r+n);
	for(int i=0;i<n;i++)
	{
		//青い点の入力
		int x,y;
		cin>>x>>y;
		for(int j=0;j<n;j++)
		{
			if(x>r[j].first && y>r[j].second)
			{
				adde(j+1,n+1+i,1);
			}
			if(x<r[j].first)
				break;
		}
	}
	while(1)
	{
		fill(used,used+202,false);
		ll f = dfs(0,2*n+1,9999999999999999);
		if(f==0)
			break;
		ans+=f;
	}
	cout<<ans<<endl;
	return 0;
}