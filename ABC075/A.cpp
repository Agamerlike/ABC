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
	int ans=0;
	
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]<a[1])
	{
		ans=a[0];
	}else{
		ans=a[2];
	}
	
	cout<<ans<<endl;
	return 0;
}