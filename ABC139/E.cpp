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
int a[1000][1000];
int p[1000];//現在何番目
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			cin>>a[i][j];
			a[i][j]--;
		}
		a[i][n-1]=1e8-1;
	}
	fill(p,p+1000,0);
	//0との試合位置に着目
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[i][j]==0)
				p[i]=j+1;
		}
	}
	ans=n-1;
	ans+=n-2-p[a[0][n-2]]+1;
	//照合する
	int last=a[0][n-2];//0が最後に戦う相手
	for(int i=p[last];i<n-1;i++)
	{
		for(int j=0;j<p[a[last][i]];j++)
		{
			if(a[a[last][i]][j]==last)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}