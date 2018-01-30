#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int money[32501];
int main()
{
	for(int i=0;i<32501;i++)
	{
		money[i]=0;
	}
	int a,b,c,x;
	int ans;
	cin>>a>>b>>c>>x;
	for(int aa=0;aa<a+1;aa++)
	{
		for(int bb=0;bb<b+1;bb++)
		{
			for(int cc=0;cc<c+1;cc++)
			{
				int xx=500*aa+100*bb+50*cc;
				money[xx]++;
			}
		}
	}
	ans = money[x];
	cout<<ans<<endl;
	return 0;
}