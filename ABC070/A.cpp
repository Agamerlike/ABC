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
	int n;
	int keta1,keta2;
	int ans=0;
	
	cin>>n;
	keta1=n%10;
	keta2=n/100;
	if(keta1==keta2)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}