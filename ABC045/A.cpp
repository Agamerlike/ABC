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
	int a,b,h;
	int ans=0;
	
	cin>>a>>b>>h;
	ans=(a+b)*h/2;
	cout<<ans<<endl;
	return 0;
}