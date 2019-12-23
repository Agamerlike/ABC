#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
ll dist[300][300];
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
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dist[i][j]<=l)
				dist[i][j]=1;
			else
				dist[i][j]=1e14-1;
		}
	}
	//wf2
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
		if(dist[s][t]==1e14-1)
			cout<<-1<<endl;
		else
			cout<<dist[s][t]-1<<endl;
	}
	return 0;
}