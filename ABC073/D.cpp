#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int n,m,r;
int rr[8];
bool used[8];
int d[200][200];
int minr;

int main()
{
	int ans=99999999;
	cin>>n>>m>>r;
	fill(d[0],d[200],99999999);
	fill(used,used+8,false);
	for(int i=0;i<r;i++)
	{
		cin>>rr[i];
		rr[i]--;
	}
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		d[a][b]=c;
		d[b][a]=c;
	}

	//ワーシャルフロイド
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}

	sort(rr,rr+r);
	minr=99999999;
	do
	{
		int t=0;
		for(int i=1;i<r;i++)
		{
			t += d[rr[i-1]][rr[i]];
		}
		if(minr>t)
			minr=t;
	}while(next_permutation(rr,rr+r));
	cout<<minr<<endl;
	return 0;
}