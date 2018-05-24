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
	int p=0;//パーの回数
	int g=0;//グーの回数
	int ans=0;
	
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='p')
			p++;
		else
			g++;
	}
	ans+=(g-p)/2;
	cout<<ans<<endl;
	return 0;
}