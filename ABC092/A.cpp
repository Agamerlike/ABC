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
	if(a<b)
	{
		ans+=a;
	}else{
		ans+=b;
	}
	if(c<d)
	{
		ans+=c;
	}else{
		ans+=d;
	}
	cout<<ans<<endl;
	return 0;
}