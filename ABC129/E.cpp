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
ll dp[100003][2]; //i番目の桁までの総数、ただしj=1のときは最大値上回る危険
int main()
{
	ll ans=0;
	string l;
	cin>>l;
	int n=l.size();
	fill(dp[0],dp[100003],0);
	dp[0][1]=2;
	dp[0][0]=1;
	for(int i=1;i<n;i++)
	{
		if(l[i]=='0')
		{
			dp[i][0]=dp[i-1][0]*3;
			dp[i][0]%=MOD;
			dp[i][1]=dp[i-1][1];
		}else{
			dp[i][0]=dp[i-1][0]*3;
			dp[i][0]%=MOD;
			dp[i][1]=dp[i-1][1]*2;
			dp[i][1]%=MOD;
			dp[i][0]+=dp[i-1][1];
			dp[i][1]%=MOD;
		}
	}
	ans=dp[n-1][0]+dp[n-1][1];
	ans%=MOD;
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}