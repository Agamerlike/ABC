#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	string n;
	char c;
	int cnt=0;
	int max=0;
	
	cin>>n;
	c=n[0];
	cnt++;
	max++;
	for(int i=1;i<4;i++)
	{
		if(c==n[i])
		{
			cnt++;
		}else{
			c=n[i];
			if(max<cnt)
			{
				max=cnt;
			}
			cnt=1;
		}
	}
	if(max<cnt)
	{
		max=cnt;
	}
	if(max>2)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}