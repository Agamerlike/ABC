#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

//ll rui[100001]; //累積積 rui[i]=s[i-1]*s[i]*...*s[0], rui[0]=1
ll s[100000];
int main()
{
	int n;
	ll k;
	int ans=0;
	int cnt=0;
	cin>>n>>k;
	bool f=false;//0が含まれていれば無条件ですべて含める
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]==0)
			f=true;
		if(s[i]>k)
			cnt++;
	}
	if(f)
		ans=n;
	else if(cnt==n)
		ans=0;
	else{
		//しゃくとり
		int l=0;
		int r=0;
		ll now=1;
		ans=1;
		for(r=0;r<n;r++)
		{
			now*=s[r];
			while(now>k)
			{
				now/=s[l];
				l++;
			}
			//cerr<<l<<" "<<r<<" "<<now<<endl;
			ans=max(r-l+1,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}