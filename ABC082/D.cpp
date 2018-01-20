#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

vector<int> xy[2];
int dp[20001];//10000を0とする

int main()
{
	string s;
	int x,y;
	int ans=0;
	int cnt=0;
	int tt=0;
	cin>>s;
	cin>>x>>y;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='F')
		{
			cnt++;
		}else{
			xy[tt].push_back(cnt);
			cnt=0;
			tt++;
			tt%=2;
		}
	}
	//テスト出力
	/*
	cerr<<"("<<x<<","<<y<<")"<<endl;
	cerr<<"x: ";
	for(int i=0;i<xy[0].size();i++)
	{
		cerr<<xy[0][i]<<" ";
	}
	cerr<<endl;
	cerr<<"y: ";
	for(int i=0;i<xy[1].size();i++)
	{
		cerr<<xy[1][i]<<" ";
	}
	cerr<<endl;
	*/
	//x
	for(int i=0;i<20001;i++)
	{
		dp[i]=-1;
	}
	xy[tt].push_back(cnt);
	dp[10000+xy[0][0]]=1;
	xy[0].erase(xy[0].begin());
	for(int i=0;i<xy[0].size();i++)
	{
		for(int j=0;j<20001;j++)
		{
			if(dp[j]>0)
			{
				if(dp[j]!=i+2)
				{
					dp[j]=-1;
					if(j+xy[0][i]<20001)
					{
						dp[j+xy[0][i]]=i+2;
					}
					if(j-xy[0][i]>0)
					{
						dp[j-xy[0][i]]=i+2;
					}
				}
			}
		}
	}
	cerr<<dp[10000+x]<<endl;
	if(dp[10000+x]!=xy[0].size()+1)
	{
		cerr<<"x check"<<endl;
		cout<<"No"<<endl;
		return 0;
	}
	//y
	for(int i=0;i<20001;i++)
	{
		dp[i]=-1;
	}
	dp[10000]=1;
	for(int i=0;i<xy[1].size();i++)
	{
		for(int j=0;j<20001;j++)
		{
			if(dp[j]>0)
			{
				if(dp[j]!=i+2)
				{
					dp[j]=-1;
					if(j+xy[1][i]<20001)
					{
						dp[j+xy[1][i]]=i+2;
					}
					if(j-xy[1][i]>0)
					{
						dp[j-xy[1][i]]=i+2;
					}
				}
			}
		}
	}
	cerr<<dp[10000+y]<<endl;
	if(dp[10000+y]==xy[1].size()+1)
	{
		cout<<"Yes"<<endl;
	}else{
		cerr<<"y check"<<endl;
		cout<<"No"<<endl;
	}
	return 0;
}