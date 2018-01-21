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
	if((a*b)%2==0)
	{
		cout<<"Even"<<endl;
	}else{
		cout<<"Odd"<<endl;
	}
	return 0;
}