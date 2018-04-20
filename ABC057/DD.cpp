#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll v[51];
ll p[51][51];

void ptable()
{
	for(int i=0;i<51;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			if(j==0 || j==i)
				p[i][j]=1;
			else
				p[i][j]=p[i-1][j-1]+p[i-1][j];
		}
	}
}

int main()
{
	int n,a,b;
	int same=0;
	ll ans=0;
	double mm=0;
	
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	reverse(v,v+n);
	ptable();

	for(int i=0;i<a;i++)
	{
		mm+=v[i];
	}
	mm/=(double)a;
	cout<<mm<<endl;

	if(v[a-1]!=v[a])
	{
		ans=1;
	}else if(v[0]==v[a]){
		same=a+1;
		while(v[0]==v[same])
		{
			same++;
		}
		for(int i=a;i<min(same,b)+1;i++)
		{
			ll c=p[same][i];
			ans+=c;
		}
	}else{
		ll c=0;
		ll d=0;
		for(int i=0;i<a;i++)
		{
			if(v[i]==v[a-1])
				c++;
		}
		d=c;
		for(int i=a;i<n;i++)
		{
			if(v[i]==v[a-1])
			{
				//cerr<<i<<" "<<v[a-1]<<" "<<v[i]<<endl;
				d++;
			}
		}
		cerr<<d<<"C"<<c<<endl;
		ans=p[d][c];
	}
	cout<<ans<<endl;
	return 0;
}