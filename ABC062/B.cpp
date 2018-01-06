#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string g[100];
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		cin>>g[i];
	}
	for(int i=0;i<w+2;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<h;i++)
	{
		g[i].insert(0,"#");
		g[i]+="#";
		cout<<g[i]<<endl;
	}	
	for(int i=0;i<w+2;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	return 0;
}