#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;

int main()
{
	int m,n;
	int i,j;
	long long f;
	long long ff;
	long long ans=0;
	long long x[100000];
	long long y[100000];
	long long s[100000];
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>y[i];
	}
	ff=(n-1)*(m-1);
	f=ff;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m-1;j++)
		{
			s[j]=(x[i+1]-x[i])*(y[j+1]-y[j]);
		}
		for(j=0;j<(m-1)/2;j++)
		{
			ans+=s[j]*f;
			ans%=MOD;
			ans+=s[m-1-j]*f;
			ans%=MOD;
			f+=2;
		}
	}
	for(i=0;i<(n-1)/2+1;i++)
	{
		for(j=0;j<(m-1)/2+1;j++)
		{
			times[i][j]=f+(i+1)*j;
			times[n-1-i][m-1-j]=f+(i+1)*j;
		}
	}

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m-1;j++)
		{
			ans+=s[i][j]*times[i][j];
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}