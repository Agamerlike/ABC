#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n,k,kk;
	ll c=0;
	ll ans=0;
	int cnt=0;
	cin>>n>>k;
	if(k==0)
	{
		ans=n*n;
	}else{
		c=k-1;
		while(c<n)
		{
			for(int b=c+1;b<n+1;b++)
			{
				ans += (n-c)/b;
			}
			c++;
		}
	}
	cout<<ans<<endl;
	return 0;
}