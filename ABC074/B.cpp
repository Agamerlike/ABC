#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n,k;
	int x[100];
	int ans=0;
	
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		if(k-x[i]<x[i])
		{
			ans += (k-x[i])*2;
		}else{
			ans += x[i]*2;
		}
	}
	cout<<ans<<endl;
	return 0;
}