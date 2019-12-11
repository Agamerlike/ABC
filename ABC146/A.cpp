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
	int n;
	string s;
	ll ans=0;
	cin>>s;
	if(s=="SUN")
		ans=7;
	if(s=="MON")
		ans=6;
	if(s=="TUE")
		ans=5;
	if(s=="WED")
		ans=4;
	if(s=="THU")
		ans=3;
	if(s=="FRI")
		ans=2;
	if(s=="SAT")
		ans=1;
	cout<<ans<<endl;
	return 0;
}