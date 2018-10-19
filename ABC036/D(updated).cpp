#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

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
bool used[100000];
ll f[100000];//自分を親とする部分木の色の取り方　ただし自分は白
ll h[100000];//自分を親とする部分木の色の取り方　ただし自分は黒

void dfs(int node,int parent)
{
	
	for(int i=0;i<g[node].size();i++)
	{
		Edge e=g[node][i];
		//親ノードならスキップ
		if(e.to==parent)
			continue;
		//まだ分かっていないなら子を探索
		if(!used[e.to])
		{
			dfs(e.to,node);
		}
		f[node]*=(f[e.to]+h[e.to]);
		f[node]%=MOD;
		h[node]*=f[e.to];
		h[node]%=MOD;
	}
	used[node]=true;
	return;
}
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	//ここからDP
	fill(f,f+n,1);
	fill(h,h+n,1);
	fill(used,used+n,false);
	int now=0;
	//葉であるノードは最初から決まっているので初期値を入れる
	for(int i=0;i<n;i++)
	{
		if(g[i].size()==1)
		{
			used[i]=true;
		}
	}
	//cerr<<"DP start"<<endl;
	//再帰探索でメモを埋めていく
	for(int i=0;i<n;i++)
	{
		if(used[i])
			continue;
		dfs(i,-1);//最初に探し始めるときには親はない
		now=i;
	}
	//ここまでDP
	/*
	cerr<<now<<endl;
	for(int i=0;i<n;i++)
		cerr<<f[i]<<" "<<h[i]<<endl;
	*/
	//最後に実行されたノードが今回のDPでの根である
	ans=f[now]+h[now];
	ans=(ans+MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}