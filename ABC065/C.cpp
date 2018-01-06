#include<iostream>
#include<cmath>

using namespace std;

long long MOD = 1e9+7;

long long time(long long n)
{
	long long ans=1;
	for(long long i=1;i<=n;i++)
	{
		ans *= i;
		ans %= MOD;
	}
	return ans;
}

int main()
{
	long long n,m;
	long long ans;
	cin>>n>>m;
	if(abs(n-m)>1)
	{
		cout<<0<<endl;
	}else{
		ans = time(n) * time(m);
		ans %= MOD;
		if(abs(n-m)==0)
		{
			ans *= 2;
			ans %= MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}