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
	int color;
	int ind;
	int from;
	int to;

	Edge(int n,int c,int i)
	{
		to=n;
		color=c;
		ind=i;
	}

	Edge(int f,int t,int c,int i)
	{
		from=f;
		to=t;
		color=c;
		ind=i;
	}
};

vector<Edge> g[100000];
int ans[100000];
bool used[100000];
int k;
void dfs(int now,int nc)
{
	int cnt=0;
	used[now]=true;
	for(int i=0;i<g[now].size();i++)
	{
		Edge e=g[now][i];
		if(!used[e.to])
		{
			if(cnt==nc)
				cnt++;
			ans[e.ind]=cnt;
			dfs(e.to,cnt);
			cnt++;
		}
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,-1,i));
		g[b].push_back(Edge(a,-1,i));
	}
	int root=0;
	for(int i=0;i<n;i++)
	{
		if(g[root].size()<g[i].size())
			root=i;
	}
	k=g[root].size();
	cout<<g[root].size()<<endl;
	dfs(root,-1);
	for(int i=0;i<n-1;i++)
		cout<<ans[i]+1<<endl;
	return 0;
}