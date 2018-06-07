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
	ll n,s;
	ll ans=-1;
	cin>>n>>s;
	ll r=(ll)sqrt(n)+1LL;
	for(ll i=2;i<r;i++)
	{
		ll cp=n;
		ll temp=0;
		while(cp!=0)
		{
			temp+=cp%i;
			cp/=i;
		}
		if(temp==s)
		{
			ans=i;
			break;
		}
		//cerr<<i<<" "<<temp<<endl;
	}
	if(ans==-1)
	{
		ll mm=1e15-1;
		//2ケタの探索
		for(ll p=1;p<r;p++)
		{
			ll q=s-p;
			ll i=(n-q)/p;
			if(i<r)
				continue; //i=1などの場合による無限ループの阻止
			ll cp=n;
			ll temp=0;
			//一意に定まるが一応実験しておく
			while(cp!=0)
			{
				temp+=cp%i;
				cp/=i;
			}
			if(temp==s)
			{
				mm=min(i,mm);
			}
		}
		if(mm<1e15-1)
			ans=mm;
	}
	
	if(s==n && ans==-1)
		ans=n+1;
	if(s==1 && ans==-1)
		ans=n;
	cout<<ans<<endl;
	return 0;
}