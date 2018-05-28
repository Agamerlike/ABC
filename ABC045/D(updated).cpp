#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <map>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

map<pair<ll,ll>,int> black;//1マスでも黒く塗られた3*3マス空間の左上の座標とそのうち塗られたマスの数
ll ans[10];

int main()
{
	ll h,w;
	int n;
	cin>>h>>w>>n;
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;

		//周囲25マスを黒く塗りつぶす
		for(ll j=a-2;j<min(a+1,h-1);j++)
		{
			for(ll k=b-2;k<min(w-1,b+1);k++)
			{
				if(j>0 && k>0)
				{
					auto temp=make_pair(j,k);
					black[temp]=black[temp]+1;
				}
			}
		}
	}

	fill(ans,ans+10,0);
	//できあがったmapの要素全てについて色を調べる
	for(auto i=black.begin();i!=black.end();i++)
	{
		ans[i->second]++;
	}
	//塗られていないものの個数
	ans[0]=(h-2)*(w-2)-black.size();


	for(int i=0;i<10;i++)
		cout<<ans[i]<<endl;
	return 0;
}