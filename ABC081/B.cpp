#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	ll a[200];
	ll l[200];
	int ans=1000;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		l[i]=0;
		while(a[i]%2==0)
		{
			a[i]/=2;
			l[i]++;
		}
		if(ans>l[i])
		{
			ans=l[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}