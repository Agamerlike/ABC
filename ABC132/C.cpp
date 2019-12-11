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
ll rui[100001];
ll d[100000];

int main()
{
	int n;
	ll ans=0;
	cin>>n;
	fill(d,d+100000,0);
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		c--;
		d[c]++;
	}
	rui[0]=0;
	for(int i=0;i<100001;i++)
		rui[i+1]=rui[i]+d[i];
	for(int i=0;i<100001;i++)
	{
		if(n-rui[i]==rui[i])
			ans++;	
	}
	cout<<ans<<endl;
	return 0;
}