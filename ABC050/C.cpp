#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N;
	int cnt=0;
	int A[100000];
	bool Ares[100000][100000];
	bool Ares2[100000];
	for(int i=0;i<100000;i++)
	{
		for(int j=0;j<100000;j++)
		{
			Ares[i][j]=false;
		}
		Ares2[i]=false;
	}
	int res;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
	}
	sort(A,A+N,[](int& x,int& y){return x > y});
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(floor(i,N-i-1)==A[j])
			{
				Ares[j][i]=true;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(Ares[j][i]==true && Are2[i]==false)
			{
				cnt++;
			}
		}
		if(cnt == 1)
		{
			Ares2[i]=true;
		}else if(cnt ==0){
			cout << cnt << endl;
			break;
		}
	}
	return 0;
}