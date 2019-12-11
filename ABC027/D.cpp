#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int main()
{
	int n;
	string s;
	char command[100004];//実際にどう動くか
	vector<pair<int,int>> mindex;//mの場所とその右にある（+の数）-（-の数）
	int ans=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='M')
			mindex.push_back(make_pair(0,i));
	}
	int pm=0;//右にある（+の数）-（-の数）
	int j=mindex.size()-1;
	for(int i=s.size()-1;i>-1;i--)
	{
		if(s[i]=='+')
			pm++;
		else if(s[i]=='-')
			pm--;
		else{
			mindex[j].first=pm;
			j--;
		}
	}
	sort(mindex.begin(),mindex.end());
	reverse(mindex.begin(),mindex.end());
	for(int i=0;i<mindex.size()/2;i++)
		command[mindex[i].second]='>';//右に行く
	for(int i=mindex.size()/2;i<mindex.size();i++)
		command[mindex[i].second]='<';//左に行く
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='M')
			command[i]=s[i];
	}

	//シミュレート
	int score=0;
	int axis=0;
	for(int i=0;i<s.size();i++)
	{
		cerr<<command[i];
		switch(command[i])
		{
			case '>':
			axis++;
			break;
			case '<':
			axis--;
			break;
			case '+':
			score+=axis;
			break;
			case '-':
			score-=axis;
			break;
		}
	}
	cerr<<endl;
	cout<<score<<endl;
	return 0;
}