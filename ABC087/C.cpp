#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int v[200][200];
bool used[200];
int d[200];
int a[200];
int main()
{
	int n;
	int ans=0;
	
	cin>>n;
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			v[i][j]=-100000;
		}
	}
	for(int i=0;i<2*n;i+=2)
	{
		//cerr<<"loop1"<<endl;
		used[i]=false;
		d[i]=-100;
		cin>>a[i];
		if(i>1)
		{
			v[i-2][i]=(a[i]);
		}
	}
	for(int i=1;i<2*n;i+=2)
	{
		//cerr<<"loop2"<<endl;
		used[i]=false;
		d[i]=-10000000;
		cin>>a[i];
		if(i>0)
		{
			v[i-1][i]=(a[i]);
		}
		if(i>1)
		{
			v[i-2][i]=(a[i]);
		}
	}
	d[0]=0;
	while(1)
	{
		int vv=-1;
		for(int u=0;u<n*2;u++)
		{
			if(used[u]==false && (vv==-1 || d[u]>d[vv]))
			{
				vv=u;
			}
		}
		if(vv==-1)
		{
			break;
		}
		used[vv]=true;
		for(int u=0;u<n*2;u++)
		{
			d[u]=max(d[u],d[vv]+v[vv][u]);
		}
	}
	for(int i=0;i<2*n;i++)
	{
		cerr<<i<<":"<<d[i]<<endl;
	}
	ans = (d[2*n-1]);
	ans+=a[0];
	cout<<ans<<endl;
	return 0;
}