#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int r,g,b;
	int num=0;
	cin>>r>>g>>b;
	num=r*100+g*10+b;
	if(num%4==0)
	{
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}