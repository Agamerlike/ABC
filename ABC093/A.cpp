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
	string s;
	int abc[26];
	fill(abc,abc+26,0);
	int ans=0;
	
	cin>>s;
	for(int i=0;i<3;i++)
	{
		abc[s[i]-'a']++;
	}
	for(int i=0;i<3;i++)
	{
		if(abc[i]==0)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}