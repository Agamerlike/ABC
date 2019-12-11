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
	string t[]={"Sunny","Cloudy","Rainy","Sunny"};
	string ans;
	cin>>s;
	if(s=="Sunny")
		ans=t[1];
	if(s=="Cloudy")
		ans=t[2];
	if(s=="Rainy")
		ans=t[3];
	
	cout<<ans<<endl;
	return 0;
}