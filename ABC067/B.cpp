#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n,k;
	int l[50];
	int ans=0;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>l[i];
	
	sort(l,l+n);
	reverse(l,l+n);
	for(int i=0;i<k;i++)
		ans+=l[i];
	cout<<ans<<endl;
	return 0;
}