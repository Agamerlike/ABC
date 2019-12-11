#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

int main()
{
	int n;
	int d[50];
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>d[i];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			ans+=d[i]*d[j];
	}
	cout<<ans<<endl;
	return 0;
}