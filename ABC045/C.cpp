#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	ll s;
	ll num[10];
	bool pp[10];//pp[1]=trueのときnum[0]とnum[1]の間に+
	ll ans=0;
	
	cin>>s;
	int index=0;
	while(s!=0)
	{
		num[index]=s%10;
		s/=10;
		index++;
	}
	for(ll bit=0;bit<pow(2,index-1);bit++)
	{
		for(int i=0;i<index-1;i++)
		{
			ll t=(bit&(ll)pow(2,i));
			if(t>0)
				pp[i+1]=true;
			else
				pp[i+1]=false;
		}

		ll temp=0;
		for(int i=index-1;i>-1;i--)
		{
			temp*=10;
			temp+=num[i];
			if(pp[i])
			{
				ans+=temp;
				temp=0;
			}
		}
		ans+=temp;
	}
	cout<<ans<<endl;
	return 0;
}