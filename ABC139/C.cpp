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
ll h[100000];
int ans[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>h[i];
	ans[n-1]=0;
	for(int i=n-2;i>-1;i--)
	{
		if(h[i]>=h[i+1])
			ans[i]=ans[i+1]+1;
		else
			ans[i]=0;
	}
	int aa=0;
	for(int i=0;i<n;i++)
		aa=max(aa,ans[i]);
	cout<<aa<<endl;
	return 0;
}