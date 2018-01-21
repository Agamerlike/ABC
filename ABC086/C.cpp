#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int x[100001];
int y[100001];
int t[100001];
int main()
{
	int n;
	int ans=0;
	int move;
	bool f=true;
	
	cin>>n;
	t[0]=0;
	x[0]=0;
	y[0]=0;
	for(int i=1;i<n+1;i++)
	{
		cin>>t[i]>>x[i]>>y[i];
	}
	for(int i=1;i<n+1;i++)
	{
		//cerr<<"loop "<<i<<endl;
		move=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		if(move>t[i]-t[i-1])
		{
			f=false;
			break;
		}else{
			move = move - (t[i]-t[i-1]);
			if(move%2!=0)
			{
				f=false;
				break;
			}
		}
	}
	if(f==true)
	{
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}