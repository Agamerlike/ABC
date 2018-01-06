#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n,k;
long long a[5000];
bool flag;

void saiki(int j,long long sum,int now)
{
	cerr<<sum<<endl;
	if(sum+a[j]>=k)
	{
		flag=true;
	}
	if(sum<k && flag==false)
	{
		for(int i=now;i<n;i++)
		{
			if(i==j)
			{
				continue;
			}
			cerr<<"saiki "<<i<<endl;
			saiki(j,sum+a[i],i+1);
		}
	}
	return;
}

int main()
{
	int ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<n;i++)
	{
		cerr<<a[i]<<endl;
		flag=false;
		saiki(i,0,0);
		if(flag==false)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}