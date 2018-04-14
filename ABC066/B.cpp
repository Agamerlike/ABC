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
	int ans=0;
	
	cin>>s;
	while(!s.empty())
	{
		bool f=true;
		s.pop_back();
		if(s.length()%2!=0)
			continue;
		
		for(int i=0;i<s.length()/2;i++)
		{
			if(s[i]!=s[i+s.length()/2])
				f = false;
		}
		if(f)
		{
			cout<<s.length()<<endl;
			return 0;
		}
	}

	cout<<0<<endl;
	return 0;
}