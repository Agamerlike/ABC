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

int hane[150];

int main()
{
	int n,x;
	ll ans=0;
	int l[100];
	cin>>n>>x;
	for(int i=0;i<n;i++)
		cin>>l[i];
	hane[0]=0;
	for(int i=0;i<n;i++)
		hane[i+1]=hane[i]+l[i];
	
	for(int i=0;i<n+1;i++)
	{
		if(hane[i]<=x)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}