#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <deque>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

deque<ll> ans;

int main()
{
	ll m,k;
	ll num[2];
	cin>>m>>k;
	if(k>=(1<<m))
	{
		cout<<-1<<endl;
		return 0;
	}
	if(k==1 && m==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	ans.push_front(k);
	ans.push_back(0LL);
	for(ll i=1;i<(1<<m);i++)
	{
		if(i==k)
			continue;
		ans.push_front(i);
		ans.push_back(i);
	}

	//余ったやつ
	if(k!=0)
	{
		ans.push_front(k);
		ans.push_back(0LL);
	}

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}