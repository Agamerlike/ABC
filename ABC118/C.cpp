#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int a[100000];

int main()
{
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ans=gcd(a[0],a[1]);
	for(int i=2;i<n;i++)
		ans=gcd(a[i],ans);
	cout<<ans<<endl;
	return 0;
}