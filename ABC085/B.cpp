#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	int d[100];
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	sort(d,d+n);
	ans++;
	for(int i=1;i<n;i++)
	{
		if(d[i-1]<d[i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}