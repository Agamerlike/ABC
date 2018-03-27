#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

string s[100];
int h,w;

int main()
{
	int a,b;
	h=100;
	w=100;
	//a..."."
	//b..."#"
	cin>>a>>b;

	//50*100のエリアにそれぞれ塗る
	//上が".",下が"#"
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<100;j++)
		{
			s[i]+='.';
			s[i+50]+='#';
		}
	}
	a--;
	b--;

	//それぞれのエリアに必要な数だけ挿入する
	//上側
	int index=0;
	while(b>50)
	{
		for(int j=0;j<100;j+=2)
		{
			s[index][j]='#';
			b--;
		}
		index+=2;
	}
	for(int i=0;i<b;i++)
	{
		s[index][i*2]='#';
	}
	//下側
	index=51;
	while(a>50)
	{
		for(int j=0;j<100;j+=2)
		{
			s[index][j]='.';
			a--;
		}
		index+=2;
	}
	for(int i=0;i<a;i++)
	{
		s[index][i*2]='.';
	}
	cout<<h<<" "<<w<<endl;
	for(int i=0;i<h;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}