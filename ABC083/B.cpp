#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int cal(int n)
{
	int r=0;
	int m=log10(n);
	int mm = pow(10,m);
	while(mm!=1)
	{
		r+=n/mm;
		n=n%mm;
		mm/=10;
	}
	r+=n;
	return r;
}
int main()
{
	int n,a,b;
	ll ans=0;
	int num;
	cin>>n>>a>>b;
	for(int i=1;i<n+1;i++)
	{
		num = cal(i);
		//cerr<<i<<" "<<num<<endl;
		if(num>=a && num<=b)
		{
			ans+=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}