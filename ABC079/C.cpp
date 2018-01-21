#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int a[4];
	int ans;
	char op[3];
	
	cin>>a[3];
	a[0]=a[3]/1000;
	a[3]%=1000;
	a[1]=a[3]/100;
	a[3]%=100;
	a[2]=a[3]/10;
	a[3]%=10;

	for(int bit=0;bit<8;bit++)
	{
		for(int i=0;i<3;i++)
		{
			if((bit&(int)pow(2,i))==pow(2,i))
			{
				op[i]='+';
			}else{
				op[i]='-';
			}
		}
		if(op[0]=='+')
		{
			ans=a[0]+a[1];
		}else{
			ans=a[0]-a[1];
		}
		for(int i=2;i<4;i++)
		{
			if(op[i-1]=='+')
			{
				ans+=a[i];
			}else{
				ans-=a[i];
			}
		}
		if(ans==7)
		{
			break;
		}
	}
	cout<<a[0]<<op[0]<<a[1]<<op[1]<<a[2]<<op[2]<<a[3]<<"=7"<<endl;
	return 0;
}