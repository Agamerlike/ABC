#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
ll bur[51];
ll pat[51];

//レベルlのバーガーをちょうどすべて食べられるか
bool allbug(int l,ll x)
{
	if(x>=bur[l])
		return true;
	else
		return false;
}

//どのバーガーの2層目まで到達するか
int bugbug(int l,ll x)
{
	if(x>=bur[l-1])
		return l;
	else
		return bugbug(l-1,x-1);
}
int main()
{
	int n;
	ll x;
	ll ans=0;
	cin>>n>>x;
	bur[0]=1;
	pat[0]=1;
	for(int i=1;i<51;i++)
	{
		bur[i]=bur[i-1]*2+3;
		pat[i]=pat[i-1]*2+1;
	}
	int l=n;
	int pl=n;
	while(x>0)
	{
		cerr<<l<<" "<<x<<endl;
		if(l>=x)
		{
			break;
		}
		if(allbug(l,x))
		{
			cerr<<"all done"<<endl;
			ans+=pat[l];
			x-=bur[l];
			x-=pl-l;
			pl=l;
			continue;
		}
		l=bugbug(l,x);
		x-=pl-(l-1);
		x-=bur[l-1];
		ans+=pat[l-1];
		if(x<=0)
			break;
		x--;
		ans++;//真ん中のpat
		l--;//レベルlのバーガーの2層目で止まるので必然的にその後調べるのはレベルl未満
		pl=l;
	}
	cout<<ans<<endl;
	return 0;
}