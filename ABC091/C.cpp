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
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i].first>>b[i].second;
		pl[b[i].first][b[i].second]++;
	}
	sort(r,r+n);
	for(int i=0;i<n;i++)
	{
		for(int j=r[i].first+1;j<200;j++)
		{
			bool f=false;
			for(int k=r[i].second+1;k<200;k++)
			{
				if(pl[j][k]>0)
				{
					ans++;
					f=true;
					pl[j][k]=0;
					cerr<<r[i].first<<" "<<r[i].second<<"\t"<<j<<" "<<k<<endl;
					break;
				}
			}
			if(f)
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}