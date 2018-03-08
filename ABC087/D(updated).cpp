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

vector<Edge> g[100000];
ll x[100000];
bool used[100000];

int saiki(int s)
{
	int b;
	for(int u=0;u<g[s].size();u++)
	{
		Edge t=g[s][u];
		if(used[t.next]==false)
		{
			x[t.next] = x[s]+t.cost;
			used[t.next]=true;
			b = saiki(t.next);
			if(b==-1)
			{
				return -1;
			}
		}else if(x[t.next]!=x[s]+t.cost){
			return -1;
		}
	}
	return 0;
}

int main()
{
	int n,m;
	int l,r,d;
	cin>>n>>m;
	fill(used,used+100000,false);
	for(int i=0;i<m;i++)
	{
		cin>>l>>r>>d;
		l--;
		r--;
		g[l].push_back(Edge(r,d));
		g[r].push_back(Edge(l,-1*d));
	}
	for(int i=0;i<n;i++)
	{
		int b=0;
		if(used[i]==false)
		{
			x[i]=0;
			b = saiki(i);
		}
		if(b==-1)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}