#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int a[100000];
int b[100000];
int c[100000];
int ab[100000];
int bc[100000];

int main()
{
	int n;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);

	for(int i=0;i<n;i++)
	{
		int* aindex = lower_bound(a,a+n,b[i]);
		int* cindex = upper_bound(c,c+n,b[i]);
		ab[i]=(int)(aindex-a);
		bc[i]=n-(int)(cindex-c);
		//cerr<<b[i]<<" "<<a[aindex]<<" "<<c[cindex]<<endl;
	}

	for(int i=0;i<n;i++)
	{
		ans += ab[i]*bc[i];
	}
	cout<<ans<<endl;
	return 0;
}