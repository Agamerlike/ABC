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
	int a,b,x;
	int ans=0;
	
	cin>>a>>b>>x;
	if(x-a<0)
	{
		cout<<"NO"<<endl;
	}else{
		if(x>a+b)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}