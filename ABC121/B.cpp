#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int a[20][20];
int b[20];
int main()
{
	int n,m,c;
	int ans=0;
	cin>>n>>m>>c;
	for(int i=0;i<m;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}

	for(int i=0;i<n;i++)
	{
		int s=0;
		for(int j=0;j<m;j++)
		{
			s+=a[i][j]*b[j];
		}
		s+=c;
		if(s>0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}