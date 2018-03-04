#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	bool c[4];
	char s[100];
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<4;i++)
	{
		c[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='P')
		{
			c[0]=true;
		}else if(s[i]=='W'){
			c[1]=true;
		}else if(s[i]=='G'){
			c[2]=true;
		}else if(s[i]=='Y'){
			c[3]=true;
		}
	}
	for(int i=0;i<4;i++)
	{
		if(c[i]==true)
		{
			ans++;
		}
	}
	if(ans==3)
	{
		cout<<"Three"<<endl;
	}else if(ans==4){
		cout<<"Four"<<endl;
	}
	return 0;
}