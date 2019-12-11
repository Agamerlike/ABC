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

ll dist[300][300];
bool used[300];
int main()
{
	int n,m;
	ll l;
	cin>>n>>m>>l;
	fill(dist[0],dist[300],1e14-1);
	for(int i=0;i<n;i++)
		dist[i][i]=0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		ll c;
		cin>>a>>b>>c;
		a--;b--;
		if(c>l)
			continue;
		dist[a][b]=min(dist[a][b],c);
		dist[b][a]=min(dist[b][a],c);
	}
	//wf
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int s,t;
		cin>>s>>t;
		s--;t--;
		//経路復元しながら調べる
		int now=s;
		ll fuel=l;
		ll su=0;
		int ans=0;
		fill(used,used+300,false);
		int prenow=-1;
		while(now!=t)
		{
			used[now]=true;
			//cerr<<su<<endl;
			for(int i=0;i<n;i++)
			{
				//cerr<<i<<" "<<su+dist[now][i]+dist[i][t]<<endl;
				if(!used[i] && su+dist[now][i]+dist[i][t]==dist[s][t] && dist[now][i]<=l)
				{
					if(fuel<dist[now][i])
					{
						fuel=l;
						ans++;
					}
					fuel-=dist[now][i];
					su+=dist[now][i];
					now=i;
					break;
				}
			}
			if(prenow==now)
			{
				ans=-1;
				break;
			}
			prenow=now;
		}
		cout<<ans<<endl;
	}
	return 0;
}