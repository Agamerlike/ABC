#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n;
	int ans=0;
	
	cin>>n;
	for(int i=1;i<n+1;i++)
		ans+=i;
	cout<<ans<<endl;
	return 0;
}