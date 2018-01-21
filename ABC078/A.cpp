#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	string x,y;
	int ans=0;
	
	cin>>x>>y;
	if(x<y)
	{
		cout<<"<"<<endl;
	}else if(x>y){
		cout<<">"<<endl;
	}else{
		cout<<"="<<endl;
	}
	return 0;
}