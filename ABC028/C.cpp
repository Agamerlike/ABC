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
	int a[5];
	vector<int> b;
	int ans=0;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			for(int k=j+1;k<5;k++)
			{
				b.push_back(a[i]+a[j]+a[k]);
			}
		}
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	cout<<b[2]<<endl;
	return 0;
}