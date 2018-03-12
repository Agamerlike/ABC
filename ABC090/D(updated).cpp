#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n,k;
	ll ans=0;
	
	cin>>n>>k;
	for(int b=1;b<n+1;b++)
	{
		ans += (n/b)*max(0,b-k) + max(0,(n%b)-k+1);
	}

	if(k==0)
	{
		ans -= n;
	}

	cout<<ans<<endl;
	return 0;
}