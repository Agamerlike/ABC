#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n;
	int ans=0;
	int ymin;
	pair<int,int> index;
	pair<int,int> r[100];
	pair<int,int> b[100];
	int pl[200][200];
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			pl[i][j]=0;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i].first>>r[i].second;
		pl[r[i].first][r[i].second]++;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i].first>>b[i].second;
	}
	sort(r,r+n);
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		index = make_pair(0,0);
		ymin=-1;
		for(int j=b[i].first-1;j>=0;j--)
		{
			for(int k=b[i].second-1;k>ymin;k--)
			{
				if(pl[j][k]>0)
				{
					if(k>ymin)
					{
						index = make_pair(j,k);
						ymin=k;
					}
				}
			}
		}
		if(ymin!=-1)
		{
			pl[index.first][index.second]--;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}