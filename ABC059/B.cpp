#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string a;
	string b;
	cin>>a;
	cin>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=a.size();i<100;i++)
	{
		a+='0';
	}
	for(int i=b.size();i<100;i++)
	{
		b+='0';
	}
	cerr<<a<<endl;
	cerr<<b<<endl;
	for(int i=99;i>=0;i--)
	{
		if(a[i]>b[i])
		{
			cout<<"GREATER"<<endl;
			return 0;
		}else if(a[i]<b[i]){
			cout<<"LESS"<<endl;
			return 0;
		}
	}
	cout<<"EQUAL"<<endl;
	return 0;
}