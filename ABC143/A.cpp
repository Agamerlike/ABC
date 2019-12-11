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
	int a,b;
	ll ans=0;
	cin>>a>>b;
	ans=max(0,a-b*2);
	cout<<ans<<endl;
	return 0;
}