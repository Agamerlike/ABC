#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <bitset>
#include <string.h>
using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;


int b[2][3];
int c[3][2];

//できあがった盤面の得点計算をする
int calcscore(int ban[][3])
{
	/*
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cerr<<ban[i][j]<<" ";
		cerr<<endl;
	}*/
	int ret=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(ban[i][j]==ban[i+1][j])
				ret+=b[i][j];
			else
				ret-=b[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			if(ban[i][j]==ban[i][j+1])
				ret+=c[i][j];
			else
				ret-=c[i][j];
	}
	return ret;
}

//盤面を計算する
int scoreattack(int turn, int ban[][3])
{
	int res = 0;
	int ret=0;
	if(turn%2==1)
		ret=-1e8+1;
	else
		ret=1e8-1;
	int cpban[3][3];
	if (turn<10)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for(int a=0;a<3;a++)
				{
					for(int b=0;b<3;b++)
						cpban[a][b]=ban[a][b];
				}
				if (cpban[i][j] != 0)
					continue;
				//cerr<<turn<<endl;
				if (turn % 2 == 1)
				{
					cpban[i][j] = 1;
					res = scoreattack(turn + 1, cpban);
					ret=max(ret,res);
				}else{
					cpban[i][j] = 2;
					res = scoreattack(turn + 1, cpban);
					ret=min(ret,res);
				}
			}
		}
	}else{
		//得点計算
		ret = calcscore(ban);
		//cerr<<ret<<endl;
	}
	return ret;
}

int main()
{
	int ban[3][3];
	int scoremax=0;
	int ans=0;
	fill(ban[0],ban[3],0);
	for (int i = 0; i < 6; i++)
	{
		cin >> b[i / 3][i % 3];
		scoremax+=b[i/3][i%3];
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> c[i / 2][i % 2];
		scoremax+=c[i/2][i%2];
	}

	ans=scoreattack(1,ban);
	cerr<<ans<<endl;
	cout<<(scoremax+ans)/2<<endl;
	cout<<(scoremax-ans)/2<<endl;
	return 0;
}