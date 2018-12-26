#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
ll h[100000];
int main()
{
	int n,k;
	ll ans=1e11-1;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>h[i];
	
	sort(h,h+n);
	for(int i=k-1;i<n;i++)
		ans=min(h[i]-h[i-(k-1)],ans);
	cout<<ans<<endl;
	return 0;
}