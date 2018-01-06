#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
	int a,b,n;
	int ans=0;
	cin>>n>>a>>b;
	if(a*n>b){
		ans=b;
	}else{
		ans=a*n;
	}
	cout<<ans<<endl;
	return 0;
}