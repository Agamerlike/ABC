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
	int n;
	int l[1000];
	int r[1000];
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		ans += (r[i]-l[i]+1);
	}
	cout<<ans<<endl;
	return 0;
}