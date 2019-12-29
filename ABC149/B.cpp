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
	ll a,b,k;
	ll ans=0;
	cin>>a>>b>>k;
	ll tak=max(0LL,a-k);
	ll ao=b;
	k-=a;
	if(k>0)
		ao=max(0LL,b-k);
	cout<<tak<<" "<<ao<<endl;
	return 0;
}