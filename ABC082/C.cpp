#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

ll a[100000];

int cnt[100001];

int main()
{
	int n;
	int ans=0;
	
	cin>>n;
	for(int i=0;i<100001;i++)
	{
		cnt[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>n)
		{
			ans++;
			i--;
			n--;
		}else{
			cnt[a[i]]++;
		}
	}

	for(int i=1;i<100001;i++)
	{
		if(cnt[i]==0)
		{
			continue;
		}
		if(cnt[i]>i)
		{
			ans += cnt[i]-i;
		}else if(cnt[i]!=i){
			ans += cnt[i];
		}
	}

	cout<<ans<<endl;
	return 0;
}