#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	int s[100];
	bool f[100];
	bool flag=true;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		ans+=s[i];
	}
	sort(s,s+n);
	for(int i=0;i<n;i++)
	{
		if(s[i]%10==0)
		{
			f[i]=true;
		}else{
			f[i]=false;
			flag=false;
		}
	}
	if(flag==true)
	{
		ans=0;
	}else{
		for(int i=0;ans%10==0;i++)
		{
			if(f[i]==false)
			{
				ans -= s[i];
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}