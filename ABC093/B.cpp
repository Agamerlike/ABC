#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int a,b,k;
	int num[200];
	int index=0;
	int ans=0;
	
	cin>>a>>b>>k;
	if(b-a+1>=k)
	{
		for(int i=a;i<a+k;i++)
		{
			num[index]=i;
			index++;
		}
		for(int i=b-k+1;i<b+1;i++)
		{
			if(num[index-1]>=i)
			{
				continue;
			}
			num[index]=i;
			index++;
		}

		for(int i=0;i<index;i++)
		{
			cout<<num[i]<<endl;
		}
	}else{
		for(int i=a;i<b+1;i++)
			cout<<i<<endl;
	}
	return 0;
}