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
	int n,k;
	cin>>n>>k;
	if(n%k==0)
		cout<<0<<endl;
	else
		cout<<1<<endl;
	return 0;
}