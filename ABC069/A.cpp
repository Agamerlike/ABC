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
	int n,m;
	int ans=0;
	
	cin>>n>>m;
	ans=(n-1)*(m-1);
	cout<<ans<<endl;
	return 0;
}