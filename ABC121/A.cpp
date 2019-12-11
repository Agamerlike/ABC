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
	int h,w;
	int nh,nw;
	int ans=0;
	cin>>h>>w;
	cin>>nh>>nw;
	ans=(h-nh)*(w-nw);
	cout<<ans<<endl;
	return 0;
}