#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a,b,c,d,e,f;
	int ans;
	int aa,bb,cc,dd;
	int dmin;
	int pmax;//濃度の最大
	
	cin>>a>>b>>c>>d>>e>>f;
	for(int ee=1;ee<f/100+1;ee++)
	{
		aa=-1;
		bb=-1;
		dmin=100000;//誤差の最小値
		//考えられるa,bの組み合わせを求める
		for(int i=0;i*a<ee;i++)
		{
			if((ee-i*a)%b==0)
			{
				aa=i;
				bb=(ee-i*a)/b;
				break;
			}
		}
		if(aa==-1 || bb== -1)
		{
			continue;
		}
		//cとdの組み合わせを求める
		for(int i=0;i*c<ee*e+1;i++)
		{
			cc=i;
			dd=(ee*e-c*cc)/d;
			if(ee*e-i*c-dd*d<dmin)
			{
				cc=i;
				dd=
			}
		}

	}
	cout<<ans<<endl;
	return 0;
}