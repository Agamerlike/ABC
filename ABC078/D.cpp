#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	ll z,w;
	ll a[2000];
	ll x,y;//xとyが最終的に持っているカード
	ll score;
	ll maxscore=0;
	
	cin>>n>>z>>w;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//xがi枚目までを引く
	for(int i=0;i<n;i++)
	{
		x=z;
		y=w;
		score = abs(z-w);
		for(int j=i;j<n;j++)
		{
			y=a[j];
			if(score>abs(x-y))
			{
				score=abs(x-y);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}