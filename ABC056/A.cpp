#include <iostream>

using namespace std;

int main()
{
	char a,b;
	char ans;
	cin>>a>>b;
	if(a=='H')
	{
		if(b=='H')
		{
			ans='H';
		}else if(b=='D'){
			ans='D';
		}
	}else if(a=='D'){
		if(b=='H')
		{
			ans='D';
		}else if(b=='D'){
			ans='H';
		}
	}
	cout<<ans<<endl;
	return 0;
}