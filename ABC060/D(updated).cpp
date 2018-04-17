#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int w[101];
int v[101];
vector<int> vw[4];

int main()
{
	int n,we;
	int wm[4];
	ll ans=0;
	
	cin>>n>>we;
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
	}
	vw[0].push_back(v[0]);
	for(int i=1;i<n;i++)
		vw[w[i]-w[0]].push_back(v[i]);
	wm[0]=we/w[0];
	wm[1]=we/(w[0]+1);
	wm[2]=we/(w[0]+2);
	wm[3]=we/(w[0]+3);
	for(int i=0;i<4;i++)
	{
		sort(vw[i].begin(),vw[i].end());
		reverse(vw[i].begin(),vw[i].end());
	}

	for(int a=0;a<min(wm[0]+1,(int)vw[0].size()+1);a++)
	{
		for(int b=0;b<min(wm[1]+1,(int)vw[1].size()+1);b++)
		{
			for(int c=0;c<min(wm[2]+1,(int)vw[2].size()+1);c++)
			{
				for(int d=0;d<min(wm[3]+1,(int)vw[3].size()+1);d++)
				{
					if(w[0]*(a+b+c+d)+(b+c+d)+(c+d)+d<=we)
					{
						//cerr<<"loop"<<endl;
						ll val=0;
						for(int i=0;i<a;i++)
							val+=vw[0][i];
						for(int i=0;i<b;i++)
							val+=vw[1][i];
						for(int i=0;i<c;i++)
							val+=vw[2][i];
						for(int i=0;i<d;i++)
							val+=vw[3][i];
						if(val>ans)
							ans=val;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}