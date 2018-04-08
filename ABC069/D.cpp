#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int a[10000];
string s[100];

int main()
{
	int h,w;
	int n;
	int ans=0;
	int index=0;
	
	cin>>h>>w;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(index<n)
			{
				while(a[index]==0)
				{
					index++;
					if(index>=n)
						break;
				}
				char c = min(index+1,n)+'0';
				s[i]+=c;
				a[index]--;
				while(a[index]==0)
				{
					index++;
					if(index>=n)
						break;
				}
			}else{
				char c=(index)+'0';
				s[i]+=c;
			}
		}
		i++;
		if(i==h)
			break;
		for(int j=0;j<w;j++)
		{
			if(index<n)
			{
				while(a[index]==0)
				{
					index++;
					if(index>=n)
						break;
				}
				char c=min(index+1,n)+'0';
				s[i]+=c;
				a[index]--;
				while(a[index]==0)
				{
					index++;
					if(index>=n)
						break;
				}
			}else{
				char c=(index)+'0';
				s[i]+=c;
			}
		}
		reverse(s[i].begin(),s[i].end());
	}
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cout<<s[i][j];
			if(j<w-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}