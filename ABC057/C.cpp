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
	ll n;
	ll sqn;
	ll a,b;
	ll ans;
	ll i=2;
	int cnt=0;
	a=1;
	b=1;
	
	cin>>n;
	sqn=sqrt(n);
	while(i<=sqn)
	{
		cerr<<n<<endl;
		if(n%i==0)
		{
			n=n/i;
			if(cnt%2==0)
			{
				a=a*i;
				//cerr<<a<<endl;
			}else{
				b=b*i;
				//cerr<<b<<endl;
			}
			cnt++;
		}else{
			i++;
		}
	}
	if(n!=1 && a==1 && b==1)
		a=n;
	cerr<<a<<" "<<b<<endl;
	ans = max((ll)log10(a),(ll)log10(b))+1;
	cout<<ans<<endl;
	return 0;
}