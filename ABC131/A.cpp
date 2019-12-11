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
	if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3])
		cout<<"Bad"<<endl;
	else
		cout<<"Good"<<endl;
	//cout<<ans<<endl;
	return 0;
}