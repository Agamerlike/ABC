#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	string s;
	int a=0;
	int z=0;
	int ans=0;
	
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		{
			a=i;
			break;
		}
	}
	for(int i=s.length()-1;i>-1;i--)
	{
		if(s[i]=='Z')
		{
			z=i;
			break;
		}
	}
	ans=z-a+1;
	cout<<ans<<endl;
	return 0;
}