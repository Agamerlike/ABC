#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int a[200000];
int c[200000];
int main()
{
	int n,k;
	int ans=0;
	
	cin>>n>>k;
	for(int i=0;i<200000;i++)
	{
		c[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	sort(c,c+200000);
	reverse(c,c+200000);
	for(int i=k;i<200000;i++)
	{
		ans+=c[i];
	}
	cout<<ans<<endl;
	return 0;
}