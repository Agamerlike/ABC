#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
bool dp[101];

int main()
{
	fill(dp,dp+101,false);
	dp[0]=true;
	for(int i=0;i<100;i++)
	{
		for(int j=100;j>-1;j--)
		{
			if(dp[j])
			{
				if(j+4<101)
					dp[j+4]=true;
				if(j+7<101)
					dp[j+7]=true;
			}
		}
	}
	int n;
	cin>>n;
	if(dp[n])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}