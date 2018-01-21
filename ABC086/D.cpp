#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

ll x[100000];
ll y[100000];
char c[100000];

int main()
{
	int n,k;
	int M=0;
	int cnt=0;
	int xl,xr,yd,yu;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>c[i];
	}
	//x
	for(xl=0;xl<k;xl++)
	{
		//y
		for(yd=0;yd<k;yd++)
		{
			cnt=0;
			//初期位置白
			for(int i=0;i<n;i++)
			{
				int diffx=x[i]-xl;
				int diffy=y[i]-yd;
				char cc;
				if(diffx<0&&diffy<0)
				{
					cc='W';
				}else if(diffx<0||diffy<0){
					cc='B';
				}else{
					int divx = diffx/k;
					int divy = diffy/k;
					int s = divx+divy;
					if(s%2==0)
					{
						cc='W';
					}else{
						cc='B';
					}
				}
				if(cc==c[i])
				{
					cnt++;
				}
			}
			if(M<cnt)
			{
				M=cnt;
			}
			//初期位置黒
			cnt = n-cnt;
			if(M<cnt)
			{
				M=cnt;
			}
		}
	}
	cout<<M<<endl;
	return 0;
}