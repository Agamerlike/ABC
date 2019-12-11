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
	int from;
	int to;
	int cost;

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

vector<Edge> g[22];
ll income[22];

int main()
{
	int n;
	cin>>n;
	for(int i=2;i<n+1;i++)
	{
		int b;
		cin>>b;
		g[b].push_back(Edge(i,1));
	}
	fill(income,income+22,-1);
	for(int i=1;i<n+1;i++)
	{
		if(g[i].size()==0)//部下がいないなら給料は1
			income[i]=1;
	}
	while(income[1]==-1)
	{
		for(int i=1;i<n+1;i++)
		{
			if(income[i]!=-1)
				continue;
			ll dai=0;
			ll syou=1e17-1;
			bool f=true;
			for(int j=0;j<g[i].size();j++)
			{
				Edge k=g[i][j];
				if(income[k.to]==-1)//1つでも求まっていない社員がいれば探索を打ち切り
				{
					f=false;
					break;
				}
				
				if(dai<income[k.to])
					dai=income[k.to];
				if(syou>income[k.to])
					syou=income[k.to];
			}
			if(f)
				income[i]=dai+syou+1;
		}
	}
	cout<<income[1]<<endl;
	return 0;
}