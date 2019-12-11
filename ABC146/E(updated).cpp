#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll a[200000];
ll rui[200001];
map<ll,int> mp;
int main()
{
	int n;
	ll k;
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	rui[0]=0;
	for(int i=0;i<n;i++)
		rui[i+1]=rui[i]+a[i];
	for(int i=0;i<n+1;i++)
	{
		rui[i]-=i;
		rui[i]=(rui[i]+k)%k;
		//cerr<<rui[i]<<" ";
	}
	//cerr<<endl;
	for(int i=0;i<n+1;i++)
	{
		if(i>=k)
			mp[rui[i-k]]--;
		ans+=mp[rui[i]];
		mp[rui[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}