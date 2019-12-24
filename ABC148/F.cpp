#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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

vector<Edge> g[100000];
vector<int> keiro;//u-v間の経路
bool used[100000];
bool uvpath(int s,int t,int now,int prev)
{
	if(now==t)
	{
		keiro.push_back(now);
		return true;
	}
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(e.to==prev)
			continue;
		if(uvpath(s,t,e.to,now))
		{
			keiro.push_back(now);
			return true;
		}
	}
	return false;
}
int longpath(int now,int prev,int length)
{
	int ret=length;
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(e.to==prev)
			continue;
		ret=max(ret,longpath(e.to,now,length+1));
	}
	return ret;
}

int main()
{
	int n,u,v;
	cin>>n>>u>>v;
	u--;v--;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	uvpath(u,v,u,-1);
	// for(int i=0;i<keiro.size();i++)
	// 	cerr<<keiro[i]<<" ";
	// cerr<<endl;
	reverse(keiro.begin(),keiro.end());
	int midp=((int)keiro.size()/2)-1;//高橋が引き返す地点のインデックス
	int l=longpath(keiro[midp],keiro[midp+1],0); //引き返してからどれくらい進めるか
	//cerr<<keiro.size()<<" "<<midp<<" "<<keiro[midp]<<" "<<keiro[midp+1]<<" "<<l<<endl;
	int ans=l+midp;//高橋くんが逃げる距離
	if(keiro.size()&1)
		ans++;
	cout<<ans<<endl;
	return 0;
}