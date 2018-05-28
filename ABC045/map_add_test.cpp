/*
# mapの加算テストプログラム

標準入力で入力した数字の数だけ単語を入力し、単語とその単語が入力された回数を出力する。
*/

#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main()
{
	map<string,int> m;
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		s.clear();
		cin>>s;
		m[s]=m[s]++;
	}
	//valueでのsortはできない（エラーを吐く）
	//sort(m.begin(),m.end());
	for(auto i=m.begin();i!=m.end();i++)
		cout<<i->first<<" "<<i->second<<endl;
	return 0;
}