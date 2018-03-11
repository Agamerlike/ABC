#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

float dp[3000][3000];
int a,b,c,d,e,f;
float pmax=0;//濃度の最大
pair<int,int> maxindex;

int fullwater(int now,bool af)
{
	if(af==true)
	{
		if(now+a<=f)
		{
			dp[now+a][0]=0;
			fullwater(now+a,true);
			fullwater(now+a,false);
		}
	}else{
		if(now+b<=f)
		{
			dp[now+b][0]=0;
			fullwater(now+b,true);
			fullwater(now+b,false);
		}
	}
	return 0;
}

int fullsugar(int now,int water,bool cf)
{
	if(cf==true)
	{
		if(e*water/100<now+c && now+c+water<=f)
		{
			dp[water][now+c]=(now+c)/water;
			if(pmax<dp[water][now+c])
			{
				pmax = dp[water][now+c];
				maxindex = make_pair(water,now+c);
			}
			fullsugar(now+c,water,true);
			fullsugar(now+c,water,false);
		}
	}else{
		if(e*water/100<now+d && now+d+water<=f)
		{
			dp[water][now+d]=(now+d)/water;
			if(pmax<dp[water][now+d])
			{
				pmax = dp[water][now+d];
				maxindex = make_pair(water,now+d);
			}
			fullsugar(now+d,water,true);
			fullsugar(now+d,water,false);
		}
	}
	return 0;
}

int main()
{
	int sugar,water;
	int ww=0;
	fill(dp[0],dp[3000],(float)-1);
	dp[0][0]=0;
	maxindex = make_pair(0,0);
	cin>>a>>b>>c>>d>>e>>f;
	a*=100;
	b*=100;
	fullwater(0,true);
	fullwater(0,false);
	for(int i=0;i<=f;i++)
	{
		if(dp[i][0]>-1)
		{
			fullsugar(0,i,true);
			fullsugar(0,i,false);
		}
	}
	cout<<maxindex.first<<" "<<maxindex.second<<endl;
	return 0;
}