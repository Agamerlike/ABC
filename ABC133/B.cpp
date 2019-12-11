#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
const double EPS=1e-9;
double ten[10][10];

double dist(int x,int y,int d)
{
	double sum=0.0;
	for(int i=0;i<d;i++)
	{
		sum+=(ten[x][i]-ten[y][i])*(ten[x][i]-ten[y][i]);
	}
	return sqrt(sum);
}
int main()
{
	int n,d;
	ll ans=0;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d;j++)
			cin>>ten[i][j];
	}

	for(int x=0;x<n;x++)
	{
		for(int y=x+1;y<n;y++)
		{
			double kyori=dist(x,y,d);
			if(abs(kyori-floor(kyori))<EPS)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}