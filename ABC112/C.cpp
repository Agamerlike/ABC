
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int n;
int x[100];
int y[100];
ll h[100];

bool fff(int cx,int cy,ll ch)
{
	for(int i=0;i<n;i++)
	{
		ll ih=max(ch-abs(cx-x[i])-abs(cy-y[i]),0LL);
		if(ih!=h[i])
			return false;
	}
	return true;
}

int main()
{
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i]>>h[i];
	
	//最大高さを調べる
	ll mh=0;
	for(int i=0;i<n;i++)
		mh=max(mh,h[i]);

	//それぞれの座標ごとにmh+200まで調べる
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		{
			for(ll k=0;k<201;k++)
			{
				if(fff(i,j,k+mh))
				{
					cout<<i<<" "<<j<<" "<<k+mh<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}