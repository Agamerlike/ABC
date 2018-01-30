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
	int cost;
	int next;

	Edge(int n,int c)
	{
		next=n;
		cost=c;
	}
};

vector<Edge> g[200];
int maxd[200];
bool used[200];

int main()
{
	for(int i=0;i<200;i++)
	{
		used[i]=false;
		maxd[i]=-1;
	}
	maxd[0]=0;
	int n,s;
	int ans;
	cin>>n;
	//1行目
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		if(i>0)
		{
			g[i-1].push_back(Edge(i,c));
		}
		if(i==0)
		{
			s=c;
		}
	}
	//2行目
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		//cerr<<i%n<<endl;
		if(i>0)
		{
			g[n+i-1].push_back(Edge(n+i,c));
		}
		g[i].push_back(Edge(n+i,c));
	}

	//ダイクストラ
	while(1)
	{
		int v=-1;
		for(int u=0;u<2*n;u++)
		{
			if(used[u]==false && (v==-1 || maxd[u]>maxd[v]))
			{
				v=u;
			}
		}
		if(v==-1)
		{
			break;
		}
		used[v]=true;
		for(int i=0;i<g[v].size();i++)
		{
			Edge e = g[v][i];
			if(maxd[e.next] < maxd[v]+e.cost)
			{
				maxd[e.next] = maxd[v]+e.cost;
			}
		}
	}
	ans = maxd[2*n-1];
	ans += s;
	cout<<ans<<endl;
	return 0;
}