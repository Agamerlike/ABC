#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long a[100000];

int main()
{
	int n;
	long long sum=0;
	long long ans=0;
	bool flag=true;
	bool nextflag=true;
	bool zeroflag=false;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[0]<0)
	{
		flag=false;
	}
	sum += a[0];
	for(int i=1;i<n;i++)
	{
		sum += a[i];
		if(sum<0)
		{
			nextflag=false;
		}else if(sum>0){
			nextflag=true;
		}else{
			zeroflag=true;
		}
		if(flag==nextflag)
		{
			if(nextflag==true)
			{
				if(sum>=0)
				{
					ans += (sum+1);
					sum= -1;
				}
				flag=false;
			}else{
				if(sum<=0)
				{
					ans += (sum*-1+1);
					sum = 1;
				}
				flag=true;
			}
		}else if(zeroflag==true){
			cerr<<"0!"<<endl;
			if(flag==true)
			{
				sum=-1;
				ans++;
				flag=false;
			}else{
				sum=1;
				ans++;
				flag=true;
			}
		}else{
			flag=nextflag;
		}
		zeroflag=false;
		cerr<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}