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
	int a[3];
	int d[3];
	int ans=0;
	int odd=0;
	
	cin>>a[0]>>a[1]>>a[2];
	for(int i=0;i<3;i++)
	{
		if(a[i]%2==1)
			odd++;
	}
	if(odd==1)
	{
		for(int i=0;i<3;i++)
		{
			if(a[i]%2==0)
				a[i]++;
		}
		ans++;
	}else if(odd==2){
		for(int i=0;i<3;i++)
		{
			if(a[i]%2==1)
				a[i]++;
		}
		ans++;
	}
	d[0]=0;
	sort(a,a+3);
	for(int i=0;i<3;i++)
	{
		ans += (a[2]-a[i])/2;
	}
	cout<<ans<<endl;
	return 0;
}