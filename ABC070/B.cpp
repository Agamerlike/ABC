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
	int a,b,c,d;
	int ans=0;
	
	cin>>a>>b>>c>>d;
	if(b<c || d<a)
	{
		ans=0;
	}else{
		ans = min(b,d)-max(a,c);
	}
	cout<<ans<<endl;
	return 0;
}