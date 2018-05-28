#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;


string a,b,c;

char turn(int p)
{
	char ret,temp;
	switch(p)
	{
		case 0:
		if(a.length()==0)
			return 'A';
		temp=a[a.size()-1];
		a.pop_back();
		switch(temp)
		{
			case 'a':
			ret=turn(0);
			break;
			case 'b':
			ret=turn(1);
			break;
			case 'c':
			ret=turn(2);
			break;
		}
		break;
		case 1:
		if(b.length()==0)
			return 'B';
		temp=b[b.size()-1];
		b.pop_back();
		switch(temp)
		{
			case 'a':
			ret=turn(0);
			break;
			case 'b':
			ret=turn(1);
			break;
			case 'c':
			ret=turn(2);
			break;
		}
		break;
		case 2:
		if(c.length()==0)
			return 'C';
		temp=c[c.size()-1];
		c.pop_back();
		switch(temp)
		{
			case 'a':
			ret=turn(0);
			break;
			case 'b':
			ret=turn(1);
			break;
			case 'c':
			ret=turn(2);
			break;
		}
		break;
	}
	return ret;
}

int main()
{
	char ans;
	
	cin>>a;
	cin>>b;
	cin>>c;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	ans = turn(0);
	cout<<ans<<endl;
	return 0;
}