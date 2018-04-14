#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int x[200000];
int y[200000];

int main()
{
	int n;
	int ans=0;
	int mid;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		y[i]=x[i];
	}
	sort(y,y+n);

	mid = (n+1)/2;

	for(int i=0;i<n;i++)
	{
		if(x[i]<y[mid])
		{
			cout<<y[mid]<<endl;
		}else{
			cout<<y[mid-1]<<endl;
		}
	}
	return 0;
}