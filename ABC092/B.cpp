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
	int n,d,x;
	int a[100];
	int ans=0;
	
	cin>>n>>d>>x;
	ans=x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans += d/a[i];
		if(d%a[i]!=0)
		{
			ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}