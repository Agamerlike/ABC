#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

string ken="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWW";
map<int,string> m;
int main()
{
	string s;
	int ans=0;
	m[0]="Do";
	m[2]="Re";
	m[4]="Mi";
	m[5]="Fa";
	m[7]="So";
	m[9]="La";
	m[11]="Si";
	cin>>s;
	ans=ken.find(s);
	cout<<m[ans]<<endl;
	return 0;
}