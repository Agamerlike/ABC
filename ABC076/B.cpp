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
	ll now = 1;
	int ans=0;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		if(now<k)
		{
			now*=2;
		}else{
			now+=k;
		}
	}
	cout<<now<<endl;
	return 0;
}