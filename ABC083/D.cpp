#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
	string s;
	int ans;
	int tmp;
	
	
	cin>>s;
	ans=s.length();
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			tmp = max(i+1,(int)s.length()-i-1);
			ans = max(ans,i+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}