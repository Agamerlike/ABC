#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <functional>
typedef long long ll;

using namespace std;

typedef pair<int,int> P;

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
int a[100000];
int d[100000];
bool used[10];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n-1;i++)
	{
		g[i].push_back(Edge(i+1,abs(a[i+1]-a[i])));
		if(i!=n-2)
			g[i].push_back(Edge(i+2,abs(a[i+2]-a[i])));
	}

	//ダイクストラ
	priority_queue<P,vector<P>,greater<P>> que;
	fill(d,d+100000,1e9-1);
	d[0]=0;
	que.push(P(0,0));
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		
		for(int i=0;i<g[v].size();i++)
		{
			Edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	cout<<d[n-1]<<endl;
	return 0;
}