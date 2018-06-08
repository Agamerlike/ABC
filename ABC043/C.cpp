#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int a[100];

int main()
{
	int n;
	ll ans=0;
	ll minc=1e15-1;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=-100;i<101;i++)
	{
		ll cost=0;
		for(int j=0;j<n;j++)
		{
			cost+=(i-a[j])*(i-a[j]);
		}
		if(cost<minc)
		{
			minc=cost;
			ans=a[i];
		}
	}
	cout<<minc<<endl;
	return 0;
}