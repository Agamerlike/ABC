#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
pair<int,int> a[100000];
int b[100000];
int main()
{
	int n;
	//int ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a[i]=make_pair(t,i);
	}
	sort(a,a+n);
	int tmp=0;
	b[a[0].second]=tmp;
	for(int i=1;i<n;i++)
	{
		if(a[i].first!=a[i-1].first)
			tmp++;
		b[a[i].second]=tmp;
	}
	
	for(int i=0;i<n;i++)
		cout<<b[i]<<endl;
	return 0;
}