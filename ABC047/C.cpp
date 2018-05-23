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
	int n;
	int bw=0;
	int ans=0;
	bool f;
	
	cin>>s;
	n=s.length();
	int i=0;
	while(i<n)
	{
		f=false;
		if(s[i]=='W')
		{
			while(s[i]=='W' && i<n)
				i++;
			while(s[i]=='B' && i<n)
			{
				f=true;
				i++;
			}
			if(f)
				bw++;
		}else{
			while(s[i]=='B' && i<n)
				i++;
			while(s[i]=='W' && i<n)
			{
				f=true;
				i++;
			}
			if(f)
				bw++;
		}
		//cerr<<i<<" "<<bw<<endl;
	}
	if(bw==0)
	{
		if(s[0]=='W')
			ans=0;
		else
			ans=0;
	}else{
		ans=bw*2;
		if(f)
			ans--;
	}
	cout<<ans<<endl;
	return 0;
}