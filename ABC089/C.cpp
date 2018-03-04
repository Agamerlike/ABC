#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

string s[100000];

int main()
{
	int n;
	ll M[5];
	ll ans=0;
	ll temp;
	int bit=0;
	int cnt=0;
	
	cin>>n;
	for(int i=0;i<5;i++)
	{
		M[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		switch(s[i][0])
		{
			case 'M':
			M[0]++;
			break;
			case 'A':
			M[1]++;
			break;
			case 'R':
			M[2]++;
			break;
			case 'C':
			M[3]++;
			break;
			case 'H':
			M[4]++;
			break;
		}
	}
	for(bit=0;bit<32;bit++)
	{
		cnt=0;
		temp=1;
		for(int i=0;i<5;i++)
		{
			int t = bit&(int)pow(2,i);
			if(t>0)
			{
				temp*=M[i];
				cnt++;
			}
		}
		if(cnt==3)
		{
			ans+=temp;
		}
	}
	cout<<ans<<endl;
	return 0;
}