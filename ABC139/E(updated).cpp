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
int now[1000];
bool flag[1000];
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
	fill(chan,chan+1000,true);
	for(int i=0;i<n;i++)
		now[i]=a[i][p[i]];
	bool f=true;
	while(f)
	{
		f=false;
		fill(flag,flag+1000,false);
		ans++;
		//照合する
		for(int i=0;i<n;i++)
		{
			if((!flag[i]) && p[i]<n-1 && (!flag[now[i]]) && now[now[i]]==i)
			{
				f=true;
				p[i]++;
				p[now[i]]++;
				flag[i]=true;
				flag[now[i]]=true;
				now[now[i]]=a[now[i]][p[now[i]]];
				now[i]=a[i][p[i]];
			}else{
				chan[i]=false;
			}
		}
	}
	//check
	for(int i=0;i<n;i++)
	{
		if(p[i]!=n-1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans-1<<endl;
	return 0;
}
