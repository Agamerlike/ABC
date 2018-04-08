#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100000];


int main()
{
	int n;
	int cnt[3];
	ll ans=0;
	fill(cnt,cnt+3,0);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%4==0)
		{
			cnt[2]++;
			ans+=2;
		}else if(a[i]%2==0){
			cnt[1]++;
			ans++;
		}else{
			cnt[0]++;
		}
	}

	ll s = n - n%2;
	if(ans<s)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}