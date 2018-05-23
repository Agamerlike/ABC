#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100000];
int amin[100000];//iまでのa[i]の最小値のi
ll m[100000];//iで売ったときの利益の最大値
int mmin[100000];//iで売ったときの買った地点 
vector<int> cheap;//買った地点を集めたもの

int main()
{
	int n;
	ll t;
	ll ans=0;
	
	
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//最小値のindexを求める
	amin[0]=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[amin[i-1]])
			amin[i]=i;
		else
			amin[i]=amin[i-1];
	}

	//それぞれの地点における利益の最大値を求める
	for(int i=0;i<n;i++)
	{
		m[i]=a[i]-a[amin[i]];
		mmin[i]=amin[i];
	}

	//合計の利益の最大値を求める
	t=*max_element(m,m+n);
	//合計の利益が最大になる地点の買った位置を求める
	for(int i=0;i<n;i++)
	{
		if(m[i]==t)
		{
			bool f=true;
			for(int j=0;j<cheap.size();j++)
			{
				if(mmin[i]==cheap[j])
				{
					f=false;
					break;
				}
			}
			if(f)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}