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
	string s,t;
	ll ans=0;
	cin>>s>>t;
	for(int i=0;i<3;i++)
	{
		if(s[i]==t[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}