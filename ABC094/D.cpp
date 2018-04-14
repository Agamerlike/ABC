#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll a[100000];
ll dif[100000];

int main()
{
	int n;
	int odd;
	ll ab;
	ll mint=9999999999;
	int index=0;
	ll num1,num2;
	
	cin>>n;
	if(n%2==0)
		odd=0;
	else
		odd=1;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);

	num1 = a[0];
	ab = num1/2;

	for(int i=1;i<n;i++)
	{
		dif[i] = abs(ab-a[i]);
		if(ab<a[i])
			dif[i]-=odd;
		
		if(dif[i]<mint)
		{
			mint=dif[i];
			index=i;
		}
	}
	num2=a[index];
	
	cout<<num1<<" "<<num2<<endl;
	return 0;
}