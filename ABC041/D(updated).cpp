#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
typedef long long ll;

using namespace std;

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

vector<Edge> g[16];
ll dp[1<<16];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		g[x].push_back(Edge(y,1));
	}


	//ここからdp
	fill(dp,dp+(1<<16),0);
	dp[0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		bool now[16]; //現在立っているフラグ
		for(int j=0;j<16;j++)
		{
			int tm=(int)pow(2,j);
			int rr=(i&tm);
			if(rr>0)
				now[j]=true;
			else
				now[j]=false;
		}

		//現在訪れた地点それぞれに対して最も右に来られるか調べる
		for(int j=0;j<16;j++)
		{
			if(!now[j])
				continue;
			
			int next=0;//jから張られている辺の集合
			for(int k=0;k<g[j].size();k++)
			{
				next+=(int)pow(2,g[j][k].to);
			}
			int rr=(next&i);//これまでに訪れた頂点と被っていなければ右に来られる
			if(rr==0)
			{
				int tm=i-(int)pow(2,j);
				dp[i]+=dp[tm];
			}
		}
	}
	//ここまでdp

	cout<<dp[(1<<n) -1]<<endl;
	return 0;
}