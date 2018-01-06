#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int x;
	int i=0;
	int sum=0;
	cin>>x;
	while(sum<x)
	{
		i++;
		sum+=i;
	}
	cout<<i<<endl;
	return 0;
}