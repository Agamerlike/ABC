#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int a[15];
int x[15][15];
int y[15][15];
int ve(int bit,int n)
{
	int b[15];
	fill(b,b+15,0);
	for(int i=0;i<n;i++)
	{
		if(bit&(1<<i))
			b[i]=1;
		else
			b[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]<0)
			continue;
		for(int j=0;j<a[i];j++)
		{
			if(y[i][j]==1 && b[x[i][j]]>0)
				b[x[i][j]]++;
			else if(y[i][j]==0 && b[x[i][j]]<0)
				b[x[i][j]]--;
			else
				return 0;
		}
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]>=0)
			ret++;
	}
	return ret;
}
int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<a[i];j++)
		{
			cin>>x[i][j]>>y[i][j];
			x[i][j]--;
		}
	}
	for(int bit=0;bit<(1<<n);bit++)
	{
		ans=max(ans,ve(bit,n));
	}
	cout<<ans<<endl;
	return 0;
}