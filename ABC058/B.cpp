#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string o;
	string e;
	string p;
	int i;
	cin>>o;
	cin>>e;

	if(o.size()>e.size())
	{
		for(i=0;i<e.size();i++)
		{
			p+=o[i];
			p+=e[i];
		}
		p+=o[i];
	}else{
		for(i=0;i<e.size();i++)
		{
			p+=o[i];
			p+=e[i];
		}
	}
	cout<<p<<endl;
	return 0;
}