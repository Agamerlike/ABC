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
	int leng;
	int last;
	int ans=0;
	
	cin>>s;
	leng=s.length();
	if(s[0]==s[leng-1])
		last=3;
	else
		last=2;
	//leng-lastでターン数が求まる
	if((leng-last)%2==0)
		cout<<"Second"<<endl;
	else
		cout<<"First"<<endl;
	return 0;
}