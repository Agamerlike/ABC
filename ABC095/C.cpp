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
	ll a,b,c,x,y;
	ll ans=0;
	
	cin>>a>>b>>c>>x>>y;
	if(c*2<a+b){
		ans += min(x,y)*c*2;
		if(x>y)
		{
			if(c*2<a)
				ans+=(x-y)*c*2;
			else
				ans+=(x-y)*a;
		}else{
			if(c*2<b)
				ans+=(y-x)*c*2;
			else
				ans+=(y-x)*b;
		}
	}else{
		ans+=x*a;
		ans+=y*b;
	}
	cout<<ans<<endl;
	return 0;
}