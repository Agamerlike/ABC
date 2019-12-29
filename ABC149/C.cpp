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
vector<int> p;
bool hurui[200000];
void h()
{
	fill(hurui,hurui+200000,false);
	for(int i=2;i<200000;i++)
	{
		if(!hurui[i])
		{
			p.push_back(i);
			for(int j=i;j<200000;j+=i)
				hurui[j]=true;
		}
	}
	return;
}
int main()
{
	int x;
	ll ans=0;
	cin>>x;
	h();
	cout<<(*lower_bound(p.begin(),p.end(),x))<<endl;
	return 0;
}