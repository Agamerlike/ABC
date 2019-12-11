#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;


int main()
{
	string n;
	cin>>n;
	int ans=0;
	for(int i=0;i<2;i++)
	{
		int tmp=0;
		for(int j=0;j<2;j++)
		{
			tmp*=10;
			tmp+=n[i*2+j]-'0';
		}
		if(tmp>0 && tmp<13)
			ans+=(1<<i);
	}

	switch(ans)
	{
		case 0:
		cout<<"NA"<<endl;
		break;
		case 1:
		cout<<"MMYY"<<endl;
		break;
		case 2:
		cout<<"YYMM"<<endl;
		break;
		case 3:
		cout<<"AMBIGUOUS"<<endl;
		break;
	}
	return 0;
}