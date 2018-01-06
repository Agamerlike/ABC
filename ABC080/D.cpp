#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

float t[100000][3];

bool sim(int n,int c)
{
	bool f=true;
	int cnt=0;
	float now;
	for(int i=0;i<n;i++)
	{
		cnt=0;
		now=t[i][0];
		for(int j=0;j<n;j++)
		{
			if(now>=t[j][0]&&now<t[j][1])
			{
				cnt++;
			}
		}
		if(cnt>c)
		{
			f=false;
			break;
		}
	}
	return f;
}

int main()
{
	int n,c;
	int tmp;
	int h,l;
	
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>t[i][0]>>t[i][1]>>t[i][2];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(t[i][2]==t[j][2] && t[i][1]==t[j][0])
			{
				t[i][1]=t[j][1];
				t[j][0]=t[n-1][0];
				t[j][1]=t[n-1][1];
				t[j][2]=t[n-1][2];
				n--;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		t[i][0]-=0.5;
	}

	h=min(n,c);
	l=0;
	while(h-l>1)
	{
		int mid=(h+l)/2;
		if(sim(n,mid)==true)
		{
			h=mid;
		}else{
			l=mid;
		}
	}
	cout<<h<<endl;
	return 0;
}