#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	ll n,m;
	ll ans=0;
	
	cin>>n>>m;
	if(m==1)
	{
		m=n;
		n=1;
	}
	if(n==1&&m==1)
	{
		ans=1;
	}else if(n==1){
		ans=m-2;
	}else{
		ans=(n-2)*(m-2);
	}
	cout<<ans<<endl;
	return 0;
}