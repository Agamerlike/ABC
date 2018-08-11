#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
int bi[40];

int main()
{
	ll n;
	int keta=0;
	cin>>n;
	if(n==0)
	{
		cout<<0<<endl;
	}else{
		while(n!=0)
		{
			cerr<<n<<endl;
			ll t=pow(-2,keta+1);
			if(n%t==0)
			{
				bi[keta]=0;
			}else{
				bi[keta]=1;
				n-=pow(-2,keta);
			}
			keta++;
		}
	}
	reverse(bi,bi+40);
	bool f=false;
	for(int i=0;i<40;i++)
	{
		if(bi[i]==1)
			f=true;
		if(f)
			cout<<bi[i];
	}
	cout<<endl;
	return 0;
}