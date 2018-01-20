#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n,m;
	int min=1e6;
	int minindex,maxindex;
	int max=-1e6;
	int a[50];
	int ans[100][2];
	
	cin>>n;
	m=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(max<a[i])
		{
			max=a[i];
			maxindex=i;
		}
		if(min>a[i])
		{
			min=a[i];
			minindex=i;
		}
	}
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<2;j++)
		{
			ans[i][j]=0;
		}
	}
	
	if(abs(min)>abs(max))
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]!=min)
			{
				a[i]+=min;
				ans[m][0]=minindex+1;
				ans[m][1]=i+1;
				m++;
			}
		}
		for(int i=1;i<n;i++)
		{
			a[n-i-1]+=a[n-i];
			ans[m][0]=n-i+1;
			ans[m][1]=n-i;
			m++;
		}
	}else{
		for(int i=0;i<n;i++)
		{
			if(a[i]!=max)
			{
				a[i]+=max;
				ans[m][0]=(maxindex+1);
				ans[m][1]=(i+1);
				m++;
			}
		}
		for(int i=0;i<n-1;i++)
		{
			a[i+1]+=a[i];
			ans[m][0]=(i+1);
			ans[m][1]=(i+2);
			m++;
		}
	}
	/*
	cerr<<"err"<<endl;
	for(int i=0;i<n;i++)
	{
		cerr<<a[i]<<endl;
	}
	cerr<<"err"<<endl;
	*/
	cout<<m<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}