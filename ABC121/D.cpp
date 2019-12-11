#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
ll bit[70];

int main()
{
	ll a,b;
	ll ans=0;
	cin>>a>>b;
	fill(bit,bit+70,0);
	int i=0;
	while((ll)pow(2,i)<=b)
	{
		ll tmp=(ll)pow(2,i);
		bit[i]=(b/tmp/2-a/tmp/2)*tmp;//基本数
		cerr<<tmp<<" "<<bit[i]<<endl;
		//調整
		//下
		if(a%(tmp*2)>=tmp)
		{
			bit[i]-=a%(tmp*2)-tmp;
		}
		//上
		if(b%(tmp*2)>=tmp)
		{
			bit[i]+=b%(tmp*2)-tmp+1;
		}
		i++;
	}

	for(int j=0;j<64;j++)
	{
		//cerr<<bit[j]<<" ";
		if(bit[j]%2==1)
			ans+=(1LL<<j);
	}
	//cerr<<endl;
	cout<<ans<<endl;
	return 0;
}