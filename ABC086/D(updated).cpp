#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int x[100000];
int y[100000];
int black[2001][2001];
int white[2001][2001];
char c[100000];

/*
imosにおいて
(x1,y1)...........(x2,y2)
   |								 |
	 |								 |
   |								 |
   |								 |
(x1,y2)...........(x2,y2)
で構成される長方形の面積を求める
*/
int Square(int x1,int y1,int x2,int y2,bool B)
{
	int ret=0;
	int a,b,c;
	if(B==true)
	{
		if(y1>0)
		{
			a = black[x2][y1-1];
		}else{
			a=0;
		}
		if(x1>0)
		{
			b=black[x1-1][y2];
		}else{
			b=0;
		}
		if(y1>0&&x1>0)
		{
			c=black[x1-1][y1-1];
		}else{
			c=0;
		}
		ret = black[x2][y2]-a-b+c;
	}else{
		if(y1>0)
		{
			a = white[x2][y1-1];
		}else{
			a=0;
		}
		if(x1>0)
		{
			b=white[x1-1][y2];
		}else{
			b=0;
		}
		if(y1>0&&x1>0)
		{
			c=white[x1-1][y1-1];
		}else{
			c=0;
		}
		ret = white[x2][y2]-a-b+c;
	}
	return ret;
}

int main()
{
	int n,k;
	int M=0;
	int cnt=0;
	int xl,xr,yd,yu;
	
	cin>>n>>k;
	for(int i=0;i<2001;i++)
	{
		for(int j=0;j<2001;j++)
		{
			black[i][j]=0;
			white[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>c[i];
		x[i]%=(2*k);
		y[i]%=(2*k);
		if(c[i]=='B')
		{
			black[x[i]][y[i]]++;
		}else if(c[i]=='W'){
			white[x[i]][y[i]]++;
		}
	}
	//x方向の累積和
	for(int i=0;i<2*k;i++)
	{
		for(int j=1;j<2*k;j++)
		{
			black[j][i]=black[j][i]+black[j-1][i];
			white[j][i]=white[j][i]+white[j-1][i];
		}
	}
	//y方向の累積和
	for(int j=0;j<2*k;j++)
	{
		for(int i=1;i<2*k;i++)
		{
			black[j][i]=black[j][i]+black[j][i-1];
			white[j][i]=white[j][i]+white[j][i-1];
		}
	}
	//累積和チェック
	/*
	for(int j=0;j<2*k;j++)
	{
		for(int i=0;i<2*k;i++)
		{
			cerr<<black[i][j]<<" ";
		}
		cerr<<endl;
	}*/
	//x
	for(xl=0;xl<k;xl++)
	{
		//y
		for(yd=0;yd<k;yd++)
		{
			cnt=0;
			//初期位置白
			//白の数え上げ
			cnt += Square(xl,yd,xl+k-1,yd+k-1,false)+Square(xl+k,yd+k,2*k-1,2*k-1,false);
			if(xl>0)
			{
				cnt += Square(0,yd+k,xl-1,2*k-1,false);
			}
			if(yd>0)
			{
				cnt += Square(xl+k,0,2*k-1,yd-1,false);
			}
			if(xl>0&&yd>0)
			{
				cnt += Square(0,0,xl-1,yd-1,false);
			}
			//黒の数え上げ
			cnt += Square(xl+k,yd,2*k-1,yd+k-1,true)+Square(xl,yd+k,xl+k-1,2*k-1,true);
			if(xl>0)
			{
				cnt += Square(0,yd,xl-1,yd+k-1,true);
			}
			if(yd>0)
			{
				cnt += Square(xl,0,xl+k-1,yd-1,true);
			}
			//cerr<<"("<<xl<<","<<yd<<") ... "<<cnt<<endl;
			if(M<cnt)
			{
				M=cnt;
			}
			//初期位置黒
			cnt = n-cnt;
			if(M<cnt)
			{
				M=cnt;
			}
		}
	}
	cout<<M<<endl;
	return 0;
}