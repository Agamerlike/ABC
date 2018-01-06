#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[i-1])
		{
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<"yes"<<endl;
	return 0;
}