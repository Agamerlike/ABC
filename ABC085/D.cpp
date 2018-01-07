#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int a[100000];
int b[100000];
vector<int> bb;
int main()
{
	int n,h;
	int min=0;
	int amax,amaxi; 
	amax=0;
	cin>>n>>h;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		if(amax<a[i])
		{
			amax=a[i];
			amaxi=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(amax<=b[i])
		{
			bb.push_back(b[i]);
		}
	}
	sort(bb.begin(),bb.end());

	while(h>0 && !bb.empty())
	{
		h-=bb.back();
		bb.pop_back();
		min++;
	}
	if(h>0)
	{
		min += h/amax;
		if(h%amax!=0)
		{
			min++;
		}
	}
	cout<<min<<endl;
	return 0;
}