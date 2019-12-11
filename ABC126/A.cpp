#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;


int main()
{
	int n,k;
	string s;
	ll ans=0;
	cin>>n>>k;
	cin>>s;
	s[k-1]-=('A'-'a');
	cout<<s<<endl;
	return 0;
}