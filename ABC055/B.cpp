#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	long long MOD=1000000007;
	long long p=1;
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		p *= (long long)i;
		p = (long long)p%MOD;
	}
	//cerr<<MOD<<endl;
	cout<<p<<endl;
	return 0;
}