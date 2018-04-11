#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int q;
	ll ans=0;
	
	cin>>q;
	for(int i=0;i<q;i++)
	{
		ans=0;
		ll a,b;
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		if(a==b)
		{
			ans = 2*(a-1);
		}else if(abs(b-a)==1){
			ans = 2*(a-1);
		}else{
			ll c = sqrt(a*b);
			if(c*c==a*b)
				c--;
			
			if(c*(c+1)>a*b)
			{
				ans = 2*c-1;
				if(a<=c)
					ans--;
				if(b-c<c-a)
					ans--;
			}else{
				ans = 2*c;
				if(a<=c)
					ans--;
				if(b-c<c-a)
					ans--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}