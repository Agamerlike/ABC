#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int s[100000][3];
int t[200002];//時間ごとに録画機が使われているかどうか
int cm[200002];//時間ごとに録画機がいくつ使われているか

int main()
{
	int n,c;
	int cmmax=0;
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1]>>s[i][2];
	}
	for(int i=0;i<200002;i++)
	{
		cm[i]=0;
	}

	for(int i=1;i<c+1;i++)
	{
		for(int j=0;j<200002;j++)
		{
			t[j]=0;
		}
		for(int j=0;j<n;j++)
		{
			if(s[j][2]==i)
			{
				t[s[j][0]*2-1]++;
				t[s[j][1]*2]--;
			}
		}
		for(int j=1;j<200002;j++)
		{
			t[j]+=t[j-1];
		}
		for(int j=0;j<200002;j++)
		{
			if(t[j]>0)
			{
				cm[j]++;
			}
		}
	}

	for(int i=0;i<200002;i++)
	{
		if(cm[i]>cmmax)
		{
			cmmax=cm[i];
		}
	}

	cout<<cmmax<<endl;
	return 0;
}