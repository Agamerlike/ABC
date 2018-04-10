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

vector<Edge> g[200000];
bool used[200000];

int main()
{
	int n,m;
	cin>>n>>m;
	bool f=false;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	fill(used,used+200000,false);
	for(int i=0;i<g[0].size();i++)
	{
		Edge e = g[0][i];
		for(int j=0;j<g[e.next].size();j++)
		{
			if(g[e.next][j].next==n-1)
			{
				f=true;
				break;
			}
		}
		if(f)
			break;
	}

	if(f)
		cout<<"POSSIBLE"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}