#include <iostream>

using namespace std;

int main()
{
	int H,W;
	int H2;
	cin >> H >> W;
	H2 = H*2;
	char c[100][100];
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			cin >> c[i][j];
		}
	}
	char c2[200][100];
	for(int i=0;i<H2;i++)
	{
		for(int j=0;j<W;j++)
		{
			c2[i][j]=c[i/2][j];
		}
	}
	for(int i=0;i<H2;i++)
	{
		for(int j=0;j<W;j++)
		{
			cout << c2[i][j];
		}
		cout << endl;
	}
	return 0;
}