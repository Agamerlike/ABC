#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int ruihasi[100004]; //[i]=i番目とi+1番目の間の橋
//いくつ対立に使われているかを累積和で保存

int main()
{
	int n,m;
	int ans=0;
	
	cin>>n>>m;
	fill(ruihasi,ruihasi+100004,0);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		//1次元imos
		ruihasi[a]++;
		ruihasi[b]--;
	}

	//累積和
	for(int i=1;i<100001;i++)
		ruihasi[i]=ruihasi[i-1]+ruihasi[i];
	for(int i=0;i<100;i++)
		cerr<<ruihasi[i]<<" ";
	int mm=-1;//極値を求める
	for(int i=1;i<100001;i++)
	{
		if(ruihasi[i]>=mm)
		{
			mm=ruihasi[i];
		}else{
			ans++;
			while(ruihasi[i]>=ruihasi[i+1])
				i++;
			mm=ruihasi[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}