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

vector<Edge> g[2500];
int d[2500];
bool used[2500];
char c[51][51];

int main()
{
	int h,w;
	int white=0;
	int ans=0;
	cin>>h>>w;
	fill(d,d+2500,100000);
	fill(used,used+2500,false);
	for(int i=0;i<h;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(c[i][j]=='.')
			{
				white++;
			}
			if(c[i][j]=='#')
			{
				continue;
			}
			if(i>0&&c[i-1][j]=='.')
			{
				g[50*i+j].push_back(Edge(50*(i-1)+j,1));
			}
			if(j>0&&c[i][j-1]=='.')
			{
				g[50*i+j].push_back(Edge(50*i+j-1,1));
			}
			if(i<h-1&&c[i+1][j]=='.')
			{
				g[50*i+j].push_back(Edge(50*(i+1)+j,1));
			}
			if(j<w-1&&c[i][j+1]=='.')
			{
				g[50*i+j].push_back(Edge(50*i+j+1,1));
			}
		}
	}
	/*
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cerr<<g[50*i+j].size()<<endl;
		}
	}*/

	//ダイクストラ
	d[0]=0;
	while(true)
	{
		int v=-1;
		for(int u=0;u<2500;u++)
		{
			if(!used[u] && (v==-1 || d[u]<d[v]))
				v=u;
		}
		if(v == -1)
		{
			break;
		}
		
		used[v]=true;
		for(int u=0;u<g[v].size();u++)
		{
			Edge n = g[v][u];
			if(d[n.next]>d[v]+n.cost)
				d[n.next]=d[v]+n.cost;
		}
	}
	/*
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cerr<<d[50*i+j]<<endl;
		}
	}*/

	//塗りつぶす場所
	ans = white-d[50*(h-1)+w-1]-1;
	if(d[50*(h-1)+w-1]==100000)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}