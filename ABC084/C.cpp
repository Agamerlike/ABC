#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	int c[500];
	int s[500];
	int f[500];
	int time=0;
	
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>c[i]>>s[i]>>f[i];
	}

	for(int i=0;i<n-1;i++)
	{
		time=s[i]+c[i];
		for(int j=i+1;j<n-1;j++)
		{
			if(time<s[j])
			{
				time=s[j];
			}else if(time%f[j]!=0){
				time=f[j]*(time/f[j]+1);
			}
			time+=c[j];
		}
		cout<<time<<endl;
	}
	cout<<0<<endl;
	return 0;
}