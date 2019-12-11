#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <map>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
map<char,char> mp;
int main()
{
	char n;
	mp['A']='T';
	mp['C']='G';
	mp['G']='C';
	mp['T']='A';
	int ans=0;
	cin>>n;
	cout<<mp[n]<<endl;
	return 0;
}