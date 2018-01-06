#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N;
	unsigned long long MOD = 1000000007;
	int DP[1000];
	unsigned long long div=1;
	int d;
	for(int i=0;i<1000;i++)
	{
		DP[i]=0;
	}
	cin >> N;
	for(int i=2;i<N+1;i++)
	{
		d = i;
		for(int j=2;j<1000;j++)
		{
			while(d%j==0)
			{
				DP[j]++;
				d = d/j;
			}
			if(d==1)
			{
				break;
			}
		}
	}

	for(int i=0;i<1000;i++)
	{
		div *= (unsigned long long)(DP[i]+1);
		div = div % MOD;
		cerr << div << " ";
	}
	
	/*for(int i=0;i<992;i++)
	{
		cerr << DP[i] << " ";
	}*/
	cout << div << endl;
	return 0;
}