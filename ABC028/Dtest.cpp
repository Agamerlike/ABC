#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	ll n,b;
	ll pt=0;//総数がいくつあるか
	double ans;
	cin>>n>>b;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			for(int k=1;k<n+1;k++)
			{
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				v.push_back(k);
				sort(v.begin(),v.end());
				if(v[1]==b)
				{
					pt++;
					//cerr<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
				}
			}
		}
	}
	cout<<pt<<endl;
	ans=(double)pt/pow(n,3);
	cout<<ans<<endl;
	return 0;
}