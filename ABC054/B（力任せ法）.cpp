#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int n,m;
	char a[50][50];
	char b[50][50];
	int len;
	int flag=0;
	cin >> n >> m;
	len = n-m+1;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> b[i];
	}
	for(int i=0;i<len;i++)//a縦
	{
		for(int j=0;j<len;j++)//a横
		{
			flag = 0;
			for(int k=0;k<m;k++)//b縦
			{
				for(int l=0;l<m;l++)//b横
				{
					if(a[i+k][j+l]!=b[k][l])
					{
					flag = 1;
					break;
					}
				}
			}
			if(flag==0)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
