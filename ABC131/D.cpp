#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD = 1e9+7;

bool comp(P &lhs, P &rhs)
{
	if(lhs.second==rhs.second)
	{
		return lhs.first>rhs.first;
	}else{
		return lhs.second<rhs.second;
	}
}

P p[200000];

int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p,p+n,comp);
	ll now=0;
	bool f=true;
	for(int i=0;i<n;i++)
	{
		if(now+p[i].first<=p[i].second)
		{
			now+=p[i].first;
		}else{
			f=false;
			break;
		}
	}
	if(f)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}