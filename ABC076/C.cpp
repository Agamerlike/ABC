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
	string s,t;
	string ans;
	bool ff=false;
	
	cin>>s;
	cin>>t;
	for(int i=0;i<s.length()-t.length()+1;i++)
	{
		bool f=true;
		for(int j=0;j<t.length();j++)
		{
			if(s[i+j]!='?' && s[i+j]!=t[j])
			{
				f=false;
				break;
			}
		}
		//書き換え
		if(f)
		{
			ff=true;
			ans = s;
			for(int j=0;j<i;j++)
			{
				if(ans[j]=='?')
					ans[j]='a';
			}
			for(int j=i;j<i+t.length();j++)
			{
				ans[j]=t[j-i];
			}
			for(int j=i+t.length();j<s.length();j++)
			{
				if(ans[j]=='?')
					ans[j]='a';
			}
		}
	}
	if(ff)
		cout<<ans<<endl;
	else
		cout<<"UNRESTORABLE"<<endl;
	return 0;
}