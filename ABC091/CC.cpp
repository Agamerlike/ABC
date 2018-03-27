#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

//普通のグラフの構造体に逆辺revを加えたもの
//逆辺へのアクセスにはg[next][rev]とする
//流せる流量はcostを代用する
class Edge
{
	public:
	int cost;
	int next;
	int rev;

	Edge(int n,int r,int c)
	{
		next=n;
		rev=r;
		cost=c;
	}
};

vector<Edge> g[202];
bool used[202];
//0...s(始点)
//1～n...赤い点
//n+1～2n...青い点
//2n+1...t(終点)


//Ford-Fulkerson法用のdfs(深さ優先探索)
//v...現在の頂点
//t...ゴール
//f...現在のフローの流量
int dfs(int v,int t,int f)
{
	//現在地がゴールなら終わり
	if(v==t)
		return f;
	//そうでなければvから流れることのできる経路をすべて探索
	used[v]=true;
	for(int i=0;i<g[v].size();i++)
	{
		Edge &e = g[v][i]; //値を書き換えるので参照渡しする
		//その辺が使われていないかつまだ流せる流量が残っていればそこに流せるだけ流す
		if(!used[e.next]&&e.cost>0)
		{
			int d = dfs(e.next,t,min(f,e.cost));
			if(d>0)
			{
				//流れた分だけ流せる残量を減らし逆辺の流した量を増やす
				e.cost-=d;
				g[e.next][e.rev].cost += d;
				return d;
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	int ans=0;
	cin>>n;
	pair<int,int> r[100];
	fill(used,used+202,false);
	for(int i=0;i<n;i++)
	{
		cin>>r[i].first>>r[i].second;
	}
	//ここからグラフ作る
	//s->赤->青->tの順番で流すことを考える
	for(int i=0;i<n;i++)
	{
		g[0].push_back(Edge(i+1,g[i+1].size(),1));
		g[i+1].push_back(Edge(0,g[0].size()-1,0));
		g[n+1+i].push_back(Edge(2*n+1,g[2*n+1].size(),1));
		g[2*n+1].push_back(Edge(n+1+i,g[n+1+i].size()-1,0));
	}
	sort(r,r+n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=0;j<n;j++)
		{
			if(x>r[j].first && y>r[j].second)
			{
				g[j+1+n].push_back(Edge(j+1,g[j+1].size()-1,0));//青から赤には流せない
				g[j+1].push_back(Edge(j+1+n,g[j+1+n].size(),1));
			}
			if(x<r[j].first)
				break;
		}
	}
	//ここまで
	
	//Ford-Fulkerson
	while(1)
	{
		fill(used,used+202,false);
		int f = dfs(0,2*n+1,99999);
		if(f==0)
			break;
		ans+=f;
	}

	cout<<ans<<endl;
	return 0;
}