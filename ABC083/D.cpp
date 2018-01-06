#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

bool check(string s,int n)
{
	
}

int main()
{
	string s;
	int ans=0;
	int l,r,mid;
	
	cin>>s;
	l=1;
	r=s.length();
	while(l<r)
	{
		mid = (l+r)/2;
		if(check(s,mid)==true)
		{
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<ans<<endl;
	return 0;
}