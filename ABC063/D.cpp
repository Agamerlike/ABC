#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool dorl(int n,long long h[])
{
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(h[i]>0)
		{
			flag=true;
			break;
		}
	}
	return flag;
}

int main()
{
	int n;
	long long a,b;
	long long h[100000];
	long long ans;
	long long sum;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	while(dorl(n,h)==true)
	{
		sum=0;
		ans++;
		for(int i=0;i<n;i++)
		{
			h[i]-=b;
			if(h[i]<0)
			{
				h[i]=0;
			}
			sum+=h[i];
		}
		if(sum<(a-b)*ans)
		{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}