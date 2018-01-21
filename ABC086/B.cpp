#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	string a,b;
	int ans=0;
	int rt;
	
	cin>>a>>b;
	a += b;
	ans = atoi(a.c_str());
	//cerr<<ans<<endl;
	rt=sqrt(ans);
	if(rt*rt==ans)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}