#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int a[200000];
int b[200000];

int main()
{
	int n;
	int k;
	int index=0;
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n%2==0)
		k=n-1;
	else
		k=n-2;
	
	while(k>0)
	{
		b[index]=a[k];
		k-=2;
		index++;
	}
	for(int i=0;i<n;i+=2)
	{
		b[index]=a[i];
		index++;
	}

	if(n%2!=0)
	{
		//cerr<<"rev"<<endl;
		reverse(b,b+n);
	}
	for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}