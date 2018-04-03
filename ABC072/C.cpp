#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int inc[100000];
int a[100000];
int de[100000];

int cnt[100001];

int main()
{
	int n;
	int ans=0;
	fill(cnt,cnt+100002,0);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		inc[i]=a[i]+1;
		de[i]=a[i]-1;
	}

	for(int i=0;i<n;i++)
	{
		cnt[a[i]]++;
		cnt[inc[i]]++;
		cnt[de[i]]++;
	}

	int mindex=0;
	for(int i=1;i<100002;i++)
	{
		if(cnt[i]>cnt[mindex])
			mindex=i;
	}
	cout<<cnt[mindex]<<endl;
	return 0;
}