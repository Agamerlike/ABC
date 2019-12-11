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
	int n,a,b;
	ll ans=0;
	cin>>n>>a>>b;
	cout<<min(a*n,b)<<endl;
	return 0;
}