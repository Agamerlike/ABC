#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string s[50];
	string a;
	int cnt[26][50];
	int m[26];
	int j=0;
	int d=0;
	for(int i=0;i<26;i++)
	{
		m[i]=100;
		for(int j=0;j<50;j++)
		{
			cnt[i][j]=0;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		sort(s[i].begin(),s[i].end());
		j=0;
		d=0;
		for(char c='a';c<'z'+1;c++)
		{
			while(s[i][j]==c)
			{
				cnt[d][i]++;
				j++;
			}
			cerr<<cnt[d][i];
			d++;
			if(j==s[i].size())
			{
				break;
			}
		}
	}

	for(int i=0;i<26;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(m[i]>cnt[i][j])
			{
				m[i]=cnt[i][j];
			}
		}
	}

	for(int i=0;i<26;i++)
	{
		cerr<<m[i];
		for(int j=0;j<m[i];j++)
		{
			a += ('a'+i);
		}
	}
	cout<<a<<endl;
	return 0;
}