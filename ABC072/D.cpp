#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int p[100001];

int main()
{
	int n;
	int ans=0;
	
	cin>>n;
	for(int i=1;i<n+1;i++)
		cin>>p[i];
	
	for(int i=1;i<n+1;i++)
	{
		if(p[i]==i)
		{
			ans++;
			int t=p[i+1];
			p[i+1]=p[i];
			p[i]=t;
		}
	}
	cout<<ans<<endl;
	return 0;
}