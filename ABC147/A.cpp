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
int main()
{
	int a,b,c;
	ll ans=0;
	cin>>a>>b>>c;
	if(a+b+c<=21)
		cout<<"win"<<endl;
	else
		cout<<"bust"<<endl;
	return 0;
}