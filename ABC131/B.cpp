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
	int n;
	int l;
	ll now=1e8-1;
	ll tar=0;
	ll ans=-1;
	cin>>n>>l;
	for(int i=1;i<n+1;i++)
		tar+=l+i-1;
	for(int i=1;i<n+1;i++)
	{
		ll tmp=0;
		for(int j=1;j<n+1;j++)
		{
			if(i==j)
				continue;
			tmp+=l+j-1;
		}
		if(now>abs(tar-tmp))
		{
			now=abs(tar-tmp);
			ans=tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}