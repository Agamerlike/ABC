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
	int x,t;
	int ans=0;
	
	cin>>x>>t;
	if(x>t)
	{
		ans=x-t;
	}else{
		ans=0;
	}
	cout<<ans<<endl;
	return 0;
}