#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;


int main()
{
	int n;
	ll l[87];
	l[0]=2;
	l[1]=1;
	for(int i=2;i<87;i++)
	{
		l[i]=l[i-1]+l[i-2];
	}
	ll ans=0;
	
	cin>>n;
	ans = l[n];
	cout<<ans<<endl;
	return 0;
}