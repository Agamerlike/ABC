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
	ll ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!(i&1) && s[i]=='L')
		{
			cout<<"No"<<endl;
			return 0;
		}else if((i&1) && s[i]=='R'){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}