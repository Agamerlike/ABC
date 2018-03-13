#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int r,g;
	int ans=0;
	
	cin>>r>>g;
	ans = 2*g-r;
	cout<<ans<<endl;
	return 0;
}