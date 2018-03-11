#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n,k;
	ll c=0;
	ll ans=0;
	
	cin>>n>>k;
	for(int a=k;a<n+1;a++)
	{
		for(int b=k+1;b<n+1;b++)
		{
			if(a%b>=k)
			{
				ans++;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}