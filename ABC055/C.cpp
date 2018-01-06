#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long n,m;
	long long scc=0;
	cin>>n>>m;
	if(n<m/2)
	{
		scc+=n;
		m-=n*2;
		scc+=m/4;
	}else{
		scc+=m/2;
	}
	cout<<scc<<endl;
	return 0;
}