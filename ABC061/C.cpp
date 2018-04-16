#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;
pair<ll,ll> ab[100000];
int main()
{
	int n;
	ll k;
	ll s=0;
	ll ans=0;
	int index=0;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>ab[i].first>>ab[i].second;

	sort(ab,ab+n);

	while(s<k)
	{
		if(index==n)
			break;
		s+=ab[index].second;
		index++;
	}
	index--;
	ans = ab[index].first;
	cout<<ans<<endl;
	return 0;
}