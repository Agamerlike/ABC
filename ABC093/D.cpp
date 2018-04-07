#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100];
ll b[100];

int main()
{
	int q;
	ll ans=0;
	
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a[i]>>b[i];
	}

	for(int i=0;i<q;i++)
	{
		ans=0;
		if(a[i]<b[i])
		{
			ans+=(a[i]-1);
			//big
			ll aa=a[i]+1;
			ll bb=b[i]-1;
			ll diff=aa*bb-a[i]*b[i];
			ll cnt=diff/aa+1;
			cerr<<"err>"<<cnt<<endl;
			ans+=b[i]-cnt-1;
		}else if(a[i]>b[i]){
			ans+=(b[i]-1);
			//big
			ll aa=a[i]-1;
			ll bb=b[i]+1;
			ll diff=aa*bb-a[i]*b[i];
			ll cnt=diff/bb+1;
			cerr<<"err>"<<cnt<<endl;
			ans+=a[i]-cnt-1;
		}else{
			ans+=(a[i]-1);
			ans+=(b[i]-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}