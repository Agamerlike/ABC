#include <iostream>

using namespace std;

int m,n;
int s;

int keiro(int g[][8],int past[],int now)
{
	int past2[8];
	int flag=0;
	for(int i=0;i<8;i++)
	{
		past2[i]=past[i];
	}
	past2[now]=1;
	for(int i=0;i<n;i++)
	{
		if(g[now][i]==1 && past2[i]==0)
		{
			s += keiro(g,past2,i);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(past2[i]==0)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		return 1;
	}else{
		return 0;
	}
}

int main()
{
	int a[28];
	int b[28];
	int g[8][8];
	int past[8];
	s=0;
	cin >> n >> m;
	for(int i=0;i<8;i++)
	{
		past[i]=0;
		for(int j=0;j<8;j++)
		{
			g[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		cin >> a[i] >> b[i];
		g[a[i]-1][b[i]-1]=1;
		g[b[i]-1][a[i]-1]=1;
	}
	
	s += keiro(g,past,0);

	cout << s << endl;
	return 0;
}