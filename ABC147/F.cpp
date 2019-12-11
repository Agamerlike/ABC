#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const ll MOD = 1e9+7;
set<P> st[2];
int main()
{
	int n;
	ll x,d;
	ll ans=0;
	cin>>n>>x>>d;
	if(d==1 || d==-1)
	{
		if(n%4==3 || n%4==0)
			ans++;
		ans+=n*2;
		cout<<ans<<endl;
		return 0;
	}
	if(d==0)
	{
		cout<<1<<endl;
		return 0;
	}
	st[1].insert(P(0LL,0));
	for(int i=0;i<n;i++)
	{
		if(0LL==x+(ll)i*d)
		{
			st[i&1]=st[(i+1)&1];
			continue;
		}
		st[i&1].clear();
		for(auto itr=st[(i+1)&1].begin();itr!=st[(i+1)&1].end();itr++)
		{
			st[i&1].insert(*itr);
			st[i&1].insert(P((*itr).first+(ll)i,(*itr).second+1));
		}
	}
	cout<<st[(n-1)&1].size()<<endl;
	return 0;
}