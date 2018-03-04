#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
typedef long long ll;

using namespace std;

int A[300][300];
int L[100000];
int R[100000];
map<int,pair<int,int>> mp;
int cost[90001];

int main()
{
	int h,w,d,q;
	ll ans=0;
	cin>>h>>w>>d;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>A[i][j];
			mp[A[i][j]]=make_pair(j,i);
		}
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>L[i]>>R[i];
	}
	for(int j=0;j<d;j++)
	{
		cost[j]=0;
		for(int i=j+d;i<90001;i+=d)
		{
			cost[i]=cost[i-d]+(abs(mp[i].first-mp[i-d].first)+abs(mp[i].second-mp[i-d].second));
		}
	}

	for(int i=0;i<q;i++)
	{
		ans = cost[R[i]]-cost[L[i]];
		cout<<ans<<endl;
	}
	return 0;
}