#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
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
vector<int> path; 
int d[100000];
int pre[100000];
bool used[100000];
int fe[100000];

int dfs(int s,int f)
{
	fe[s]=f;
	for(int i=0;i<g[s].size();i++)
	{
		Edge e = g[s][i];
		if(fe[e.next]==0)
		{
			dfs(e.next,f);
		}
	}
	return 0;
}

int main()
{
	int n;
	int keiro;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	fill(used,used+100000,false);
	fill(d,d+100000,99999999);
	//ダイクストラ
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	que.push(make_pair(0,0));
	d[0]=0;
	fill(pre,pre+100000,-1);
	while(!que.empty())
	{
		auto p = que.top();
		que.pop();
		int v = p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0;i<g[v].size();i++)
		{
			Edge e = g[v][i];
			if(d[e.next]>d[v]+e.cost)
			{
				d[e.next]=d[v]+e.cost;
				pre[e.next]=v;
				que.push(make_pair(d[e.next],e.next));
			}
		}
	}
	//ダイクストラここまで
	keiro = d[n-1];
	//経路復元
	for(int t=n-1;t!=-1;t=pre[t])
		path.push_back(t);
	reverse(path.begin(),path.end());

	//最短経路のうちフェネックの取る頂点を求める(fe=1,snuke=-1)
	fill(fe,fe+100000,0);
	for(int i=0;i<keiro/2+1;i++)
		fe[path[i]]=1;
	for(int i=keiro/2+1;i<path.size();i++)
		fe[path[i]]=-1;
	//それぞれの葉に当たるノードをすべて塗りつぶす
	for(int i=0;i<path.size();i++)
	{
		dfs(path[i],fe[path[i]]);
	}
	//累積和を取る
	keiro=0;
	for(int i=0;i<n;i++)
	{
		keiro+=fe[i];
	}
	if(keiro>0)
		cout<<"Fennec"<<endl;
	else
		cout<<"Snuke"<<endl;
	return 0;
}