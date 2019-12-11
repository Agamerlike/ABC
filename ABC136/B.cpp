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
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i<10)
			ans++;
		else if(i>=100 && i<1000)
			ans++;
		else if(i>=10000 && i<100000)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}