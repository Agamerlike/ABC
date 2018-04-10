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
	int ans=0;
	
	cin>>n;
	if(n>=64)
	{
		ans=64;
	}else if(n>=32){
		ans=32;
	}else if(n>=16){
		ans=16;
	}else if(n>=8){
		ans=8;
	}else if(n>=4){
		ans=4;
	}else if(n>=2){
		ans=2;
	}else{
		ans=1;
	}
	cout<<ans<<endl;
	return 0;
}