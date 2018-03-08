#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int c[3][3];
	int a[3];
	int b[3];
	int aa[3];
	int ans=0;
	bool f;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>c[i][j];
		}
	}

	for(int k=0;k<101;k++)
	{
		a[0]=k;
		b[0]=c[0][0]-k;
		b[1]=c[0][1]-k;
		b[2]=c[0][2]-k;
		if(b[0]<0||b[1]<0||b[2]<0)
		{
			continue;
		}
		f=true;
		for(int i=1;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				aa[j]=c[i][j]-b[j];
			}
			if(aa[0]==aa[1]&&aa[1]==aa[2])
			{
				a[i]=aa[0];
			}else{
				f=false;
				break;
			}
		}
		if(f==true)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}