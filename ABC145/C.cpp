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

	double x[8];
	double y[8];
double dist(int i,int j)
{
	return sqrtl((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main()
{
	int n;
	vector<int> v;
	double ans=0;
	double cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		v.push_back(i);
	}
	do
	{
		for(int i=1;i<n;i++)
		{
			ans+=dist(v[i-1],v[i]);
		}
		cnt++;
	}while(next_permutation(v.begin(),v.end()));
	cerr<<cnt<<endl;
	cout<<setprecision(12)<<ans/cnt<<endl;
	return 0;
}