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

int bs(int d[],int n,int t)
{
	int l=0;
	int r=n;
	if(d[n-1]<=t)
	{
		return n;
	}
	if(d[0]>t)
	{
		return 0;
	}
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(d[mid]>t)
		{
			r=mid;
		}else{
			l=mid;
		}
	}
	while(d[r]==t)
	{
		r++;
	}
	//r--;
	return r;
}

int bs2(int d[],int n,int t)
{
	int l=0;
	int r=n;
	if(d[n-1]<=t)
	{
		return n;
	}
	if(d[0]>t)
	{
		return 0;
	}
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(d[mid]<t)
		{
			l=mid;
		}else{
			r=mid;
		}
	}
	while(d[l]==t)
	{
		l--;
	}
	l++;
	return l;
}

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
		int aindex = bs2(a,n,b[i]);
		int cindex = bs(c,n,b[i]);
		ab[i]=aindex;
		bc[i]=n-cindex;
		//cerr<<b[i]<<" "<<a[aindex]<<" "<<c[cindex]<<endl;
	}

	for(int i=0;i<n;i++)
	{
		ans += ab[i]*bc[i];
	}
	cout<<ans<<endl;
	return 0;
}