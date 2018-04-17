#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	string a,b,c;
	int ans=0;
	
	cin>>a>>b>>c;
	if(a[a.length()-1]==b[0] && b[b.length()-1]==c[0])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}