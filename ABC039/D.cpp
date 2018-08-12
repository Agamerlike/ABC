#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

string s[100];
string p[100];
string ps[100];

int main()
{
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++)
		cin>>s[i];
	
	//とりあえず仮候補を作る
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='#')
			{
				//周囲を調べる
				bool f=true;
				if(i>0)
				{
					//upleft
					if(j>0 && s[i-1][j-1]=='.')
						f=false;
					//up
					if(s[i-1][j]=='.')
						f=false;
					//upright
					if(j<w-1 && s[i-1][j+1]=='.')
						f=false;
				}
				//left
				if(j>0 && s[i][j-1]=='.')
					f=false;
				//right
				if(j<w-1 && s[i][j+1]=='.')
					f=false;
				if(i<h-1)
				{
					//downleft
					if(j>0 && s[i+1][j-1]=='.')
						f=false;
					//down
					if(s[i+1][j]=='.')
						f=false;
					//downright
					if(j<w-1 && s[i+1][j+1]=='.')
						f=false;
				}

				if(f)
					p[i]+='#';
				else
					p[i]+='.';
			}else{
				p[i]+='.';
			}
		}
	}

	for(int i=0;i<h;i++)
	{
		//cerr<<p[i]<<endl;
		ps[i]+=p[i];
	}
	//仮候補を収縮する
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(p[i][j]=='#')
			{
				//周囲を調べる
				bool f=true;
				if(i>0)
				{
					//upleft
					if(j>0)
						ps[i-1][j-1]='#';
					//up
					ps[i-1][j]='#';
					//upright
					if(j<w-1)
						ps[i-1][j+1]='#';
				}
				//left
				if(j>0)
					ps[i][j-1]='#';
				//right
				if(j<w-1)
					ps[i][j+1]='#';
				if(i<h-1)
				{
					//downleft
					if(j>0)
						ps[i+1][j-1]='#';
					//down
					ps[i+1][j]='#';
					//downright
					if(j<w-1)
						ps[i+1][j+1]='#';
				}
			}
		}
	}

	bool f=true;
	for(int i=0;i<h;i++)
	{
		if(s[i]!=ps[i])
		{
			f=false;
			break;
		}
	}
	if(!f)
	{
		cout<<"impossible"<<endl;
	}else{
		cout<<"possible"<<endl;
		for(int i=0;i<h;i++)
			cout<<p[i]<<endl;
	}
		
	return 0;
}