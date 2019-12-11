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
	if(dif<1e-7)
		return true;
	else
		return false;
}
int main()
{
	double a,b,c;
	double l=1e-14;
	double r=300.0f+1e-14;
	bool f=true;
	cin>>a>>b>>c;
	double mid=(l+r)/2.0f;
	double y=a*mid+b*sin(mid*c*pi);
	while(!equal(y,100.0f))
	{

		if(y>=100.0f)
			r=mid;
		else
			l=mid;
		mid=(l+r)/2.0f;
		y=a*mid+b*sin(mid*c*pi);
	}
	cout<<setprecision(14)<<fixed<<mid<<endl;
	return 0;
}