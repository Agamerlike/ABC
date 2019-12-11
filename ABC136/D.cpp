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

int lr[2][100000];//そのマスがLのときはそのマスより左で最初にあるR
int ans[100000];
int main()
{
	string s;
	cin>>s;
	fill(lr[0],lr[2],-1);
	fill(ans,ans+100000,0);
	//Lの場合を調べる
	int last=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='R')
			last=i;
		else
			lr[0][i]=last;
	}
	last=s.size()-1;
	//Rの場合を調べる
	for(int i=s.size()-1;i>-1;i--)
	{
		if(s[i]=='L')
			last=i;
		else
			lr[1][i]=last;
	}
	for(int i=0;i<s.size();i++)
	{
		if(lr[0][i]!=-1)
		{
			int tmp=i-lr[0][i];
			if(tmp&1)
				ans[lr[0][i]+1]++;
			else
				ans[lr[0][i]]++;
		}
		if(lr[1][i]!=-1)
		{
			int tmp=lr[1][i]-i;
			if(tmp&1)
				ans[lr[1][i]-1]++;
			else
				ans[lr[1][i]]++;
		}
	}
	for(int i=0;i<s.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}