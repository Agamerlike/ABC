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
	string ans;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++)
		ans+=((s[i]-'A')+n)%26+'A';
	cout<<ans<<endl;
	return 0;
}