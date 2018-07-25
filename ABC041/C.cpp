#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n;
	pair<int,int> a[100000];
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a[i]=make_pair(t,i+1);
	}
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i].second<<endl;
	}
	return 0;
}