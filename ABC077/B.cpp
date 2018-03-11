#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	int ans=0;
	
	cin>>n;
	while(1)
	{
		int s = sqrt(n);
		if(s*s==n)
		{
			break;
		}
		n--;
	}
	cout<<n<<endl;
	return 0;
}