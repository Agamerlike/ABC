#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n,m;
	pair<int,int> ba[100000];
	int ans=0;
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		ba[i]=make_pair(b,a);
	}

	sort(ba,ba+m);
	int pre=ba[0].first-1;
	ans=1;
	for(int i=1;i<m;i++)
	{
		if(ba[i].second>pre)
		{
			ans++;
			pre=ba[i].first-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}