#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int x,y,z;
	int ans=0;
	
	cin>>x>>y>>z;
	x -= z;
	ans = x/(y+z);
	cout<<ans<<endl;
	return 0;
}