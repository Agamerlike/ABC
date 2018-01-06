#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string g[13];
	int x,y;
	g[1]="A";
	g[2]="C";
	g[3]="A";
	g[4]="B";
	g[5]="A";
	g[6]="B";
	g[7]="A";
	g[8]="A";
	g[9]="B";
	g[10]="A";
	g[11]="B";
	g[12]="A";
	cin>>x>>y;
	if(g[x]==g[y])
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}