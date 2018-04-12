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
	int a,b;
	int ans=0;
	
	cin>>a>>b;
	if(a%3==0 || b%3==0 || (a+b)%3==0)
	{
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}