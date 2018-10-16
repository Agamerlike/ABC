#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <map>
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

vector<Edge> g[100000];
pair<int,int> hako[100000];
int d[100000]; //最長路の集まり

int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int w,h;
		cin>>w>>h;
		hako[i]=make_pair(w,h);
	}
	sort(hako,hako+n);
	reverse(hako,hako+n);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			//小さい箱に対して辺を張り最大路を求める
			if(hako[i].first>hako[j].first && hako[i].second>hako[j].second)
				g[i].push_back(Edge(j,1));
		}
	}

	//始点n個すべてについて最長路を求める
	for(int i=0;i<n;i++)
	{
		//ここからベルマンフォード
		fill(d,d+n,-1e8+1);
		d[i]=0;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<g[j].size();k++)
			{
				Edge e=g[j][k];
				d[e.to]=max(d[e.to],d[j]+e.cost);//負閉路のチェックはしない
			}
		}
		//ここまでベルマンフォード
		int mm=0;
		for(int j=0;j<n;j++)
		{
			if(mm<d[j])
				mm=d[j];
		}
		ans=max(mm,ans);
	}
	cout<<ans+1<<endl;
	return 0;
}