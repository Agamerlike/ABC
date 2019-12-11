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
	ll ans=1;
	cin>>n;
	cin>>s;
	for(int i=1;i<n;i++)
	{
		if(s[i-1]!=s[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}