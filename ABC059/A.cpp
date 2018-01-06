#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	string s[3];
	string ans;
	cin>>s[0]>>s[1]>>s[2];
	for(int i=0;i<3;i++)
	{
		ans+=s[i][0];
	}
	for(int i=0;i<3;i++)
	{
		ans[i] = toupper(ans[i]);
	}
	cout<<ans<<endl;
	return 0;
}