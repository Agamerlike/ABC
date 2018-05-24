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
	int a,b,c;
	bool co[100];
	fill(co,co+100,false);
	int ans=0;
	
	cin>>a>>b>>c;
	co[a-1]=true;
	co[b-1]=true;
	co[c-1]=true;
	for(int i=0;i<100;i++)
	{
		if(co[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}