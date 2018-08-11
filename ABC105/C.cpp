#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
int bi[32];

int main()
{
	ll n;
	int ans;
	int keta=0;
	cin>>n;
	if(n==0)
	{
		cout<<0<<endl;
	}else{
		while(n!=0)
		{
			if(n>0)
			{
				for(int i=0;i<32;i++)
				{
					if(n<=pow(-2,i))
					{
						bi[i]=1;
						n-=pow(-2,i);
						break;
					}
				}
			}else{
				for(int i=0;i<32;i++)
				{
					if(n>=pow(-2,i))
					{
						bi[i]=1;
						n-=pow(-2,i);
						break;
					}
				}
			}
		}
	}
	reverse(bi,bi+32);
	bool f=false;
	for(int i=0;i<32;i++)
	{
		if(bi[i]==1)
			f=true;
		if(f)
			cout<<bi[i];
	}
	cout<<endl;
	return 0;
}