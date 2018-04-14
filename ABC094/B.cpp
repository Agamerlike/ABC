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
	int n,m,x;
	int cost[100];
	int ans=0;
	fill(cost,cost+100,0);
	cin>>n>>m>>x;
	x--;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		a--;
		cost[a]=1;
	}
	for(int i=1;i<n;i++)
	{
		cost[i]+=cost[i-1];
	}

	ans = min(cost[x],cost[n-1]-cost[x]);
	cout<<ans<<endl;
	return 0;
}