#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

class graph{
	int e;
	int n;
	graph(int next, int cost)
	{
		e=cost;
		n=next;
	}
}

int a[300][300];

int main()
{
	int n;
	ll ans;
	vector<graph> v(300);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i][i]!=0)
		{
			ans=-1;
			cout<<ans<<endl;
			return 0;
		}
	}
	
	
	cout<<ans<<endl;
	return 0;
}