#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int h,w;
	string s[50];
	int cnt=0;
	
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='#')
			{
				continue;
			}
			cnt=0;
			//左上
			if(i>0&&j>0&&s[i-1][j-1]=='#')
				cnt++;
			//上
			if(i>0 && s[i-1][j]=='#')
				cnt++;
			//右上
			if(i>0&&j<w-1&&s[i-1][j+1]=='#')
				cnt++;
			//左
			if(j>0&&s[i][j-1]=='#')
				cnt++;
			//右
			if(j<w-1&&s[i][j+1]=='#')
				cnt++;
			//左下
			if(i<h-1&&j>0&&s[i+1][j-1]=='#')
				cnt++;
			//下
			if(i<h-1&&s[i+1][j]=='#')
				cnt++;
			//右下
			if(i<h-1&&j<w-1&&s[i+1][j+1]=='#')
				cnt++;
			
			s[i][j]=(char)('0'+cnt);
		}
	}
	for(int i=0;i<h;i++)
		cout<<s[i]<<endl;
	return 0;
}