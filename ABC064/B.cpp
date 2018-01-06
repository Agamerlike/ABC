#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	int a[100];
	int ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ans = a[n-1] - a[0];
	cout<<ans<<endl;
	return 0;
}