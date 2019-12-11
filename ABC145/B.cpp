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
	cin>>n;
	cin>>s;
	if(n&1)
	{
		cout<<"No"<<endl;
	}else{
		string half;
		for(int i=0;i<n/2;i++)
			half+=s[i];
		if(s==half+half)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}