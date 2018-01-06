#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
typedef long long ll;

using namespace std;

int main()
{
	int n;
	int fn=0;
	int k;
	int nn=0;
	
	cin>>n;
	nn=n;
	k=pow(10,(int)log10(n));
	while(n>=10)
	{
		fn += n/k;
		n = n%k;
		k/=10;
	}
	fn += n;
	if(nn%fn==0)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}