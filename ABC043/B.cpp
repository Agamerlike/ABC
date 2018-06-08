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
	string ans;

	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='B')
		{
			if(ans.length()>0)
				ans.pop_back();
		}else{
			ans.push_back(s[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}