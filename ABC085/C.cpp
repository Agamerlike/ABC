#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	ll n,m;
	ll x=0;
	ll y=0;
	ll z=0;
	
	cin>>n>>m;
	m/=1000;
	x=m/10;
	m-=10*x;
	y=m/5;
	m-=5*y;
	z=m;
	//cerr<<x<<" "<<y<<" "<<z<<endl;
	if(x+y+z>n)
	{
		cout<<-1<<" "<<-1<<" "<<-1<<endl;
	}else{
		while(x>0 && x+y+z<n)
		{
			x--;
			y+=2;
			if(x+y+z+8<n)
			{
				y-=2;
				z+=10;
			}else if(x+y+z+4<n){
				y--;
				z+=5;
			}
		}
		while(y>0 && x+y+z<n){
			y--;
			z+=5;
		}
		if(x+y+z==n)
		{
			cout<<x<<" "<<y<<" "<<z<<endl;
		}else{
			cout<<-1<<" "<<-1<<" "<<-1<<endl;
		}
	}
	return 0;
}