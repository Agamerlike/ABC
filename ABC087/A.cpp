#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int x,a,b;
	int ans=0;
	
	cin>>x>>a>>b;
	x-=a;
	x-=b*(x/b);
	cout<<x<<endl;
	return 0;
}