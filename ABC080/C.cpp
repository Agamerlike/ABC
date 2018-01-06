#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>
typedef long long ll;

using namespace std;

int f[100][10];
int cnt[100];
ll p[100][11];

int main()
{
	int n,now;
	ll pp=0;
	ll max=LLONG_MIN;
	ll ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cnt[i]=0;
		for(int j=0;j<10;j++)
		{
			cin>>f[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<11;j++)
		{
			cin>>p[i][j];
		}
	}

	//ここから解答
	for(int i=1;i<1024;i++)
	{
		//各種変数の初期化
		pp=0;
		for(int j=0;j<n;j++)
		{
			cnt[j]=0;
		}
		//店ごとに開いている時間数を求める
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<10;k++)
			{
				now = i&(int)pow(2,k);//いまチェックしている時間
				if(now==(int)pow(2,k)&&f[j][k]==1)
				{
					cnt[j]++;
				}
			}
		}
		
		/*for(int j=0;j<n;j++)
		{
			cerr<<i<<":"<<cnt[j]<<endl;
		}*/
		//利益を求める
		for(int j=0;j<n;j++)
		{
			pp+=p[j][cnt[j]];
		}
		//最大値と比較する
		if(pp>max)
		{
			max=pp;
		}
	}
	cout<<max<<endl;
	return 0;
}