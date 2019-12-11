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
string s[2000];
ll tate[2000][2000];
ll yoko[2000][2000];
int main()
{
	int h,w;
	ll ans=1;
	cin>>h>>w;
	for(int i=0;i<h;i++)
		cin>>s[i];
	
	//横を調べる
	for(int i=0;i<h;i++)
	{
		int j=0;
		while(j<w)
		{
			if(s[i][j]=='#')
			{
				yoko[i][j]=0;
				j++;
			}else{
				ll cnt=0;
				while(j<w && s[i][j]=='.')
				{
					cnt++;
					yoko[i][j]=cnt;
					j++;
				}
			}
		}
		//逆から見る
		j=w-1;
		while(j>-1)
		{
			if(yoko[i][j]>0)
			{
				ll cnt=yoko[i][j];
				while(j>-1 && yoko[i][j]>0)
				{
					yoko[i][j]=cnt;
					j--;
				}
			}else{
				j--;
			}
		}
	}
	//縦を調べる
	for(int j=0;j<w;j++)
	{
		int i=0;
		while(i<h)
		{
			if(s[i][j]=='#')
			{
				tate[i][j]=0;
				i++;
			}else{
				ll cnt=0;
				while(i<h && s[i][j]=='.')
				{
					cnt++;
					tate[i][j]=cnt;
					i++;
				}
			}
		}
		//逆から見る
		i=h-1;
		while(i>-1)
		{
			if(tate[i][j]>0)
			{
				ll cnt=tate[i][j];
				while(i>-1 && tate[i][j]>0)
				{
					tate[i][j]=cnt;
					i--;
				}
			}else{
				i--;
			}
		}
	}
	//調べ終わ 
	//全座標について調べる
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='.')
			{
				if(ans<tate[i][j]+yoko[i][j]-1)
				{
					ans=tate[i][j]+yoko[i][j]-1;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}