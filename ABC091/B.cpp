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
	int n,m;
	string s[100];
	string t[100];
	int cnt=0;
	int ans=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>t[i];
	}

	for(int i=0;i<n;i++)
	{
		cnt=0;
		for(int j=0;j<n;j++)
		{
			if(s[i]==s[j])
				cnt++;
		}
		for(int j=0;j<m;j++)
		{
			if(s[i]==t[j])
				cnt--;
		}
		if(ans<cnt)
		{
			ans=cnt;
		}
	}

	cout<<ans<<endl;
	return 0;
}