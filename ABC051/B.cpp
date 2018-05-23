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
	int k,s;
	ll ans=0;
	
	cin>>k>>s;
	for(int x=0;x<k+1;x++)
	{
		for(int y=0;y<k+1;y++)
		{
			int z = s-(x+y);
			if(z<k+1 && z>-1)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}