#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include<stdlib.h>
typedef long long ll;

using namespace std;

int main()
{
	int a,b;
	int ans=0;
	string n;
	
	cin>>a>>b;
	for(int i=a;i<b+1;i++)
	{
		n = to_string(i);
		if(n[0]==n[4]&&n[1]==n[3])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}