#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100000];

int main()
{
	int n;
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);

	int i=0;
	while(i<n)
	{
		int t=a[i];
		int cnt=1;
		i++;
		while(t==a[i])
		{
			cnt++;
			i++;
		}
		if(cnt%2!=0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}