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
	int a[100];
	int alice=0;
	int bob=0;
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i+=2)
	{
		alice+=a[i];
	}
	for(int i=1;i<n;i+=2)
	{
		bob+=a[i];
	}
	ans=alice-bob;
	cout<<ans<<endl;
	return 0;
}