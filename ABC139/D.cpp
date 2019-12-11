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
	ll n;
	ll ans=0;
	cin>>n;
	ans=(1LL+n-1)*(n-1)/2;
	cout<<ans<<endl;
	return 0;
}