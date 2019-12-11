#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	int n;
	int ans=0;
	cin>>n;
	int bit[10];
	fill(bit,bit+10,0);
	for(int i=0;i<n;i++)
		cout<<"a";
	cout<<endl;
	for(int i=0;i<(int)pow(3,n)-1;i++)
	{
		string s;
		bit[0]++;
		for(int j=0;j<8;j++)
		{
			if(bit[j]==3)
			{
				bit[j+1]++;
				bit[j]=0;
			}
		}

		for(int j=0;j<n;j++)
		{
			char c=(char)('a'+bit[j]);
			string cc{c};
			s.insert(0,cc);
		}
		cout<<s<<endl;
	}
	return 0;
}