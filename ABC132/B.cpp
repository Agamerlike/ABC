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
int p[30];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	p[n]=-999;
	for(int i=1;i<n-1;i++)
	{
		int s[3]={p[i-1],p[i],p[i+1]};
		sort(s,s+3);
		if(s[1]==p[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}