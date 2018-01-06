#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	int a;
	int ans;
	
	cin>>n;
	cin>>a;
	ans = n*n - a;
	cout<<ans<<endl;
	return 0;
}