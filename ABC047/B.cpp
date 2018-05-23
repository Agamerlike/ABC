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
	int w,h,n;
	int x[100],y[100],a[100];
	int ans=0;
	int l,r,u,d; //黒く塗られた部分と白く塗られた部分の境目
	
	cin>>w>>h>>n;
	l=0;
	d=0;
	r=w;
	u=h;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i]>>a[i];
	
	for(int i=0;i<n;i++)
	{
		switch(a[i])
		{
			case 1:
				l=max(l,x[i]);
				break;
			case 2:
				r=min(r,x[i]);
				break;
			case 3:
				d=max(d,y[i]);
				break;
			case 4:
				u=min(u,y[i]);
				break;
		}
	}
	if(r-l<0 || u-d<0)
		ans=0;
	else
		ans=(r-l)*(u-d);
	cout<<ans<<endl;
	return 0;
}