#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
 
using namespace std;
 
int main()
{
	int a,b;
	int ans=0;
	
	cin>>a>>b;
	ans = (a+b)/2+((a+b)%2);
	cout<<ans<<endl;
	return 0;
}