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

ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	ll a,b,c,d;
	ll ans=0;
	cin>>a>>b>>c>>d;
	ll g=gcd(c,d);
	ll lm=c*d/g;
	ll ccnt=b/c-(a-1)/c;
	ll dcnt=b/d-(a-1)/d;
	ll cnt=b/lm-(a-1)/lm;
	cerr<<lm<<" "<<cnt<<endl;
	ans=(b-a+1)-ccnt-dcnt+cnt;
	cout<<ans<<endl;
	return 0;
}