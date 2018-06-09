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
	int a[3];
	int ans=0;
	
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]==5 && a[1]==5 && a[2]==7)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}