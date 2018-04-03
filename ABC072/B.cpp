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
	string odd;
	int ans=0;
	
	cin>>s;
	for(int i=0;i<s.length();i+=2)
	{
		odd+=s[i];
	}
	cout<<odd<<endl;
	return 0;
}