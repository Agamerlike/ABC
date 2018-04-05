#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int x,a,b;
	int ans=0;
	
	cin>>x>>a>>b;
	if(abs(a-x)>abs(b-x))
		cout<<"B"<<endl;
	else
		cout<<"A"<<endl;
	return 0;
}