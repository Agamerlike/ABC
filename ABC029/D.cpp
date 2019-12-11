#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll keta[10];
int main()
{
	ll n;
	ll ans=0;
	cin>>n;
	fill(keta,keta+10,0);
	//1桁目を調べる
	keta[0]=n/10;
	if(n%10>0)
		keta[0]++;
	//2桁目以降を調べる
	for(int i=1;i<10;i++)
	{
		ll tei=pow(10,i+1);
		keta[i]=max(0LL,n/tei)*tei/10;
		if(n%tei<tei/10)
		{
			//何も加えない
		}else if(n%tei<tei/10*2){
			int plus=n%tei-tei/10+1;//部分的に加える
			keta[i]+=plus;
		}else{
			keta[i]+=tei/10;//全部加える
		}
	}
	for(int i=0;i<10;i++)
	{
		ans+=keta[i];
		cerr<<keta[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}