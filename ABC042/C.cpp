#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int n,k,l;
	int d[10];
	int dd[10];
	int ans=0;
	
	cin>>n>>k;
	l=0;
	for(int i=0;i<k;i++)
		cin>>d[i];
	for(int i=0;i<10;i++)
	{
		bool f=true;
		for(int j=0;j<k;j++)
		{
			if(d[j]==i)
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			dd[l]=i;
			l++;
		}
	}

	for(int i=n;i<100000;i++)
	{
		//cerr<<i<<endl;
		int t=i;
		int mketa=0;
		int mk[5];
		while(t!=0)
		{
			mk[mketa]=t%10;
			t/=10;
			mketa++;
		}
		bool f=true;
		for(int j=0;j<mketa;j++)
		{
			for(int m=0;m<k;m++)
			{
				if(d[m]==mk[j])
				{
					f=false;
					break;
				}
			}
			if(!f)
				break;
		}
		if(f)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}