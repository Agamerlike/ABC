#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int gcd(int x,int y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

int main()
{
	int a,b,c;
	int ans=0;
	
	cin>>a>>b>>c;
	int g = gcd(a,b);
	if(c%g==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}