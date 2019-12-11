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
	string s;
	int ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i+1;j<s.size()+1;j++)
		{
			bool f=true;
			for(int k=i;k<j;k++)
			{
				if(!(s[k]=='A' || s[k]=='C' || s[k]=='G' || s[k]=='T'))
					f=false;
			}
			if(f)
				ans=max(ans,j-i);
		}
	}
	cout<<ans<<endl;
	return 0;
}