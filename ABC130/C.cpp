#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;


int main()
{
	double w,h,x,y;
	double mw,mh;
	ll ans=0;
	cin>>w>>h>>x>>y;
	mw=w/2.0;
	mh=h/2.0;
	if(mw==x && mh==y)
		cout<<setprecision(10)<<w*h/2<<" "<<1<<endl;
	else
		cout<<setprecision(10)<<w*h/2<<" "<<0<<endl;
	return 0;
}