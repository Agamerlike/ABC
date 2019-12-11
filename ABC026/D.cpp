#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
double pi=3.1415926535898;

//およそa=bかを判定する
bool equal(double a,double b)
{
	double dif=abs(a-b);
	if(dif<1e-6)
		return true;
	else
		return false;
}
int main()
{
	double a,b,c;
	double t=0;
	double dt;
	bool f=true;
	cin>>a>>b>>c;
	if(a>b*c*pi)
		f=false;
	if(f)
	{
		//単調増加でない場合
		t=acos(-a/b/c/pi);//単調減少の開始点(0<t<pi)
		dt=pi+(pi-t);//単調減少の終了点(pi<dt<2pi)
		t=t/c/pi;
		dt=dt/c/pi;
		while(t<2.0f/c)
			t+=2.0f/c;
		dt=-t+2.0f/c;
	}else{
		//単調増加の場合
		t=2.0f/c;
		dt=2.0f/c;
	}
	double y=a*t+b*sin(c*t*pi);
	while(y<100.0f)
	{
		t+=2.0f/c;
		dt+=2.0f/c;
		y=a*t+b*sin(c*t*pi);
	}
	//tは現在の位置の近傍にある
	double r=t;//その単調増加の中での最大点
	double l=dt-2.0f/c;//その単調増加の中での最小点
	double mid=(r+l)/2.0f;
	y=a*mid+b*sin(c*mid*pi);
	cerr<<y<<endl;
	while(!equal(100.0f,y))
	{
		cerr<<l<<" "<<r<<endl;
		//小さい場合
		if(y<100.0f)
			r=mid;
		else
			l=mid;
		mid=(l+r)/2.0f;
		y=a*mid+b*sin(c*mid*pi);
	}
	cout<<setprecision(12)<<fixed<<mid<<endl;
	return 0;
}