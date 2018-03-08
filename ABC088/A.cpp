#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n,a;
	int ans=0;
	
	cin>>n;
	cin>>a;
	if(n%500<=a)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}