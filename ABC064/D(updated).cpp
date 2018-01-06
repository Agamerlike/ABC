#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	string s;
	int d[101];
	d[0]=0;
	int x=0;
	int cnt;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			d[i+1] = d[i]+1;
		}else if(s[i]==')'){
			d[i+1] = d[i]-1;
		}
		x = min(x,d[i+1]);
	}
	cnt = (-1)*x;
	for(int i=0;i<cnt;i++)
	{
		s.insert(0,"(");
	}
	cnt = d[n] - x;
	for(int i=0;i<cnt;i++)
	{
		s += ")";
	}
	cout<<s<<endl;
	return 0;
}
