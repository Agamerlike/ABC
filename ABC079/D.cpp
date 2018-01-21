#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int v[10][10];
int A[200][200];

int main()
{
	int h,w;
	int c[10];
	ll ans=0;
	
	cin>>h>>w;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>v[i][j];
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>A[i][j];
		}
	}

	//ワーシャルフロイド
	for(int k=0;k<10;k++)
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
			}
		}
	}

	for(int i=0;i<10;i++)
	{
		c[i]=v[i][1];
		//cerr<<i<<": "<<c[i]<<endl;
	}
	c[1]=0;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(A[i][j]!=-1)
			{
				ans+=c[A[i][j]];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}