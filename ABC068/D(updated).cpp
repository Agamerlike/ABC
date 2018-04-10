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
	ll n,k;
	ll loop;
	ll a[50];
	
	cin>>k;
	n=50;
	fill(a,a+n,49);
	loop = k/n;
	for(int i=0;i<n;i++)
	{
		a[i]+=loop;
	}

	loop = k%n;

	for(int i=0;i<loop;i++)
	{
		a[i]+=n;
		for(int j=0;j<n;j++)
		{
			if(j==i)
				continue;
			a[j]--;
		}
	}
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}