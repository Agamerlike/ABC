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
	string s;
	ll ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(i>=s.size()-1-i)
			break;
		if(s[i]!=s[s.size()-1-i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}