#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
class Edge
{
	public:
	int cost;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

ll kuri2(ll a,ll x)
{
	ll ret=1;
	ll tmp=a;
	while(x>0)
	{
		if(x&1)
		{
			ret*=tmp;
			ret%=MOD;
		}
		tmp=tmp*tmp;
		tmp%=MOD;
	}
	return ret;
}

vector<Edge> g[200000];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	cout<<ans<<endl;
	return 0;
}