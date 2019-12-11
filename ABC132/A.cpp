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
	sort(s.begin(),s.end());
	if(s[0]==s[1] && s[1]!=s[2] && s[2]==s[3])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}