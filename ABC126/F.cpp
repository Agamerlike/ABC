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
int last(deque<ll> t,ll k,int mode)
{
	switch(mode)
	{
		case 0:
		t.push_back(0);
		t.push_back(k);
		break;
		case 1:
		t.push_back(0);
		t.push_front(k);
		break;
		case 2:
		t.push_front(0);
		t.push_back(k);
		break;
		case 3:
		t.push_front(0);
		t.push_front(k);
	}
	ll tmp=0;
	for(int i=1;i<t.size();i++)
	{
		if(t[i]==0)
			break;
		tmp^=t[i];
	}
	if(tmp!=k)
		return -1;
}

int main()
{
	ll m,k;
	ll ans=0;
	ll num[2];
	cin>>m>>k;
	if(k>=(1<<m))
	{
		cout<<-1<<endl;
		return 0;
	}
	ans.push_front(k);
	ans.push_back(0);
	for(int i=1;i<(1<<m);i++)
	{
		if(i==k)
			continue;
		ans.push_front(i);
		ans.push_back(i);
	}

	//余ったやつ
	ll tmp=0;
	int ind=0;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]==0)
		{
			ind=i;
			break;
		}
		tmp^=ans[i];
	}
	if(tmp==k)

	cout<<ans<<endl;
	return 0;
}