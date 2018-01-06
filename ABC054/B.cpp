#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,m;
	string a[50];
	string b[50];
	int flag=0;
	int save = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> b[i];
	}
	for(int i=0;i<n-m;i++) //縦
	{
		save = 0;
		for(int k=0;k<n-m;k++) //横
		{
			flag = 0;
			if((save = a[i].find(b[0],save))!=-1)
			{
				for(int j=1;j<m;j++)
				{
					if(a[j+i].find(b[j],save)!=save)
					{
						flag = 1;
					}
				}
			}else{
				flag = 1;
			}
			if(flag==0)
			{
				cout << "Yes"<<endl;
				return 0;
			}
			if(k<save)
			{
				k=save;
			}
		}
		//cerr << flag<<" t" <<endl;
	}
	cout << "No"<<endl;
	return 0;
}