#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int a,b,c;
	int ans=0;
	
	cin>>a>>b>>c;
	if(a+b==c || b+c==a || a+c==b)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}