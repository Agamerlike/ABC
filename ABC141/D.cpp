#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <queue>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
priority_queue<ll> que;
int main()
{
	int n,m;
	ll ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		que.push(a);
	}
	for(int i=0;i<m;i++)
	{
		ll b=que.top();que.pop();
		b/=2;
		que.push(b);
	}
	while(!que.empty())
	{
		ans+=que.top();que.pop();
	}
	cout<<ans<<endl;
	return 0;
}