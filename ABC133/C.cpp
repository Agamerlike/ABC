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

int main()
{
	ll l,r;
	ll ans=2020;
	bool f=true;
	cin>>l>>r;
	for(int i=0;i<2020;i++)
	{
		if(l+i>r)
			break;
		if((l+i)%2019==0)
		{
			f=false;
			break;
		}
	}
	for(int i=0;i<2020;i++)
	{
		if(r-i<l)
			break;
		if((r-i)%2019==0)
		{
			f=false;
			break;
		}
	}
	if(f){
		for(ll i=l;i<r;i++)
		{
			for(ll j=i+1;j<=r;j++)
			{
				if(ans>(i*j)%2019)
					ans=(i*j)%2019;
			}
		}
	}else
		ans=0;
	cout<<ans<<endl;
	return 0;
}