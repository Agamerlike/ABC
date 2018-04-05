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
	int ans=0;
	char c='a';
	bool al[26];
	fill(al,al+26,false);
	
	cin>>s;
	sort(s.begin(),s.end());

	int i=0;
	c=s[0];
	al[c-'a']=true;
	while(i<s.length())
	{
		while(s[i]==c)
		{
			i++;
		}
		c=s[i];
		al[c-'a']=true;
	}
	for(int i=0;i<26;i++)
	{
		if(!al[i])
		{
			char a='a'+i;
			cout<<a<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
}