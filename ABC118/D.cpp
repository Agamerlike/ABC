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
string dp[10100];//i本のマッチ棒で作ることのできる最大の数の組

int main()
{
	int n,m;
	char a[9];
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>a[i];
	//sort(a,a+m);
	//reverse(a,a+m);
	fill(dp,dp+10100,"0");
	//初期値は1ケタの整数
	for(int i=0;i<m;i++)
		dp[number[a[i]-'0']]=a[i];
	//ここからdp
	for(int i=1;i<10001;i++)
	{
		if(dp[i]!="0")
		{
			for(int j=0;j<m;j++)
			{
				int targetindex=i+number[a[j]-'0'];
				string temp=dp[i]+a[j];
				sort(dp[targetindex].begin(),dp[targetindex].end());
				reverse(dp[targetindex].begin(),dp[targetindex].end());
				sort(temp.begin(),temp.end());
				reverse(temp.begin(),temp.end());
				if(temp.size()>dp[targetindex].size())
					dp[targetindex]=temp;
				else if(temp.size()==dp[targetindex].size() && temp>dp[targetindex])
					dp[targetindex]=temp;
			}
		}
	}
	sort(dp[n].begin(),dp[n].end());
	reverse(dp[n].begin(),dp[n].end());
	cout<<dp[n]<<endl;
	return 0;
}
