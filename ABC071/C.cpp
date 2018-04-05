#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int a[100000];

int main()
{
	int n;
	ll ans=0;
	ll h[2];
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	h[0]=0;
	h[1]=0;
	sort(a,a+n);
	reverse(a,a+n);
	int i=0;
	int j=0;
	while(i<n-1)
	{
		if(a[i]==a[i+1])
		{
			h[j]=a[i];
			j++;
			i++;
		}
		if(j==2)
			break;
		i++;
	}
	ans=h[0]*h[1];
	cout<<ans<<endl;
	return 0;
}