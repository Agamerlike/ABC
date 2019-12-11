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
ll dp[101][8];
int w;
bool valid(int bit)
{
	//正当性チェック
	bool f=true;
	for(int b=0;b<w-1;b++)
	{
		if(bit&(1<<b))
		{
			if(b>0 && (bit&(1<<(b-1))))
			{
				f=false;
				break;
			}
			if(b<w-2 && (bit&(1<<(b+1))))
			{
				f=false;
				break;
			}				
		}
	}
	return f;
}
void update(int i,int j)
{
	ll cnt=0;
	//落下する場合を調べる
	for(int bit=0;bit<(1<<(w-1));bit++)
	{
		if(!valid(bit))
			continue;
		//jの周辺チェック
		if(!((j>0 && (bit&(1<<(j-1))))||(j<w-1 && (bit&(1<<j)))))
			cnt++;
	}
	dp[i][j]+=dp[i-1][j]*cnt;
	dp[i][j]%=MOD;
	cnt=0;
	//左からくる
	if(j>0)
	{
		for(int bit=0;bit<(1<<(w-1));bit++)
		{
			if(!valid(bit))
				continue;
			//jの周辺チェック
			if(bit&(1<<(j-1)))
				cnt++;
		}
	}
	dp[i][j]+=dp[i-1][j-1]*cnt;
	dp[i][j]%=MOD;
	cnt=0;
	//右からくる
	if(j<w-1)
	{
		for(int bit=0;bit<(1<<(w-1));bit++)
		{
			if(!valid(bit))
				continue;
			//jの周辺チェック
			if(bit&(1<<j))
				cnt++;
		}
	}
	dp[i][j]+=dp[i-1][j+1]*cnt;
	dp[i][j]%=MOD;
}
int main()
{
	int h,k;
	ll ans=0;
	cin>>h>>w>>k;
	k--;
	if(w==1)
	{
		cout<<1<<endl;
		return 0;
	}
	fill(dp[0],dp[101],0);
	dp[0][0]=1;
	for(int i=1;i<h+1;i++)
	{
		for(int j=0;j<w;j++)
		{
			update(i,j);
		}
	}
	cout<<dp[h][k]<<endl;
	return 0;
}