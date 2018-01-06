#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	int a[100];
	int rate[9];
	int zerocnt=0;
	int M=0;
	int m=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<9;i++)
	{
		rate[i]=0;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(j!=8)
			{
				if(a[i]<(j+1)*400)
				{
					rate[j]++;
					break;
				}
			}else{
				rate[8]++;
				break;
			}
		}
	}

	for(int i=0;i<9;i++)
	{
		cerr<<rate[i]<<" ";
	}
	cerr<<endl;

	for(int i=0;i<8;i++)
	{
		if(rate[i]==0)
		{
			zerocnt++;
		}else{
			m++;
		}
	}

	M = m + rate[8];
	if(m==0)
	{
		m=1;
	}

	cout<<m<<" "<<M<<endl;
	return 0;
}