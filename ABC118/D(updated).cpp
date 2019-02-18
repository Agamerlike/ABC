#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int number[10]={-1,2,5,5,4,5,6,3,7,6};
int dp[10100];//i本のマッチ棒で作ることのできる最大の数の桁

int main()
{
	int n,m;
	int a[9];
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>a[i];
	sort(a,a+m);
	reverse(a,a+m);
	fill(dp,dp+10100,-100);
	//初期値は1ケタの整数
	dp[0]=0;
	//ここからdp
	for(int i=0;i<10001;i++)
	{
		if(dp[i]!=-100)
		{
			for(int j=0;j<m;j++)
			{
				dp[i+number[a[j]]]=max(dp[i+number[a[j]]],dp[i]+1);
			}
		}
	}
	//ここまでdp
	cerr<<dp[n]<<endl;
	//ここからO(n)で下っていく
	//dp[n-number[k]]=dp[n]-1　が成立するならkは使われている
	int used[10];
	fill(used,used+10,0);
	int index=n;
	while(index!=0)
	{
		for(int i=0;i<m;i++)
		{
			if(index-number[a[i]]>=0 && dp[index-number[a[i]]]==dp[index]-1)
			{
				index-=number[a[i]];
				used[a[i]]++;
				break;
			}
		}
	}

	for(int i=9;i>-1;i--)
	{
		for(int j=0;j<used[i];j++)
			cout<<i;
	}
	cout<<endl;
	return 0;
}
