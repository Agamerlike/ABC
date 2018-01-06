#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long a[300000];
long long sa[300000];
map<long long,int> na;
bool f[300000];
long long aa[200000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n)
	{
		cin>>a[i];
		sa[i]=a[i];
		f[i]=false;
	}
	sort(sa,sa+n);
	for(int i=0;i<3*n;i++)
	{
		na[sa[i]]=i;
	}
	for(int i=0;i<3*n/2;i++)
	{
		if(na[a[i]]<3*n/2)
	}
	return 0;
}