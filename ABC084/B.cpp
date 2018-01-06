#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
	int a,b;
	string s;
	bool f=true;
	int ans=0;
	
	cin>>a>>b;
	cin>>s;
	if(s[a]=='-'){
		for(int i=0;i<a+b+1;i++)
		{
			if(i!=a)
			{
				if(s[i]=='-')
				{
					f=false;
				}
			}
		}
	}else{
		f=false;
	}
	if(f==true)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}