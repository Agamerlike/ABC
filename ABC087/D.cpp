#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int l[200000];
int r[200000];
int d[200000];
ll x[100000];
bool used[100000];
int main()
{
	int n,m;
	int ans=0;
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>l[i]>>r[i]>>d[i];
		l[i]--;
		r[i]--;
	}
	fill(used,used+100000,false);
	x[l[0]] = 0;
	x[r[0]] = d[0];
	used[l[0]]=true;
	used[r[0]]=true;
	for(int i=1;i<m;i++)
	{
		if(used[l[i]]==true && used[r[i]]==true)
		{
			if(x[r[i]]!=d[i]+x[l[i]])
			{
				cout<<"No"<<endl;
				return 0;
			}
		}else if(used[l[i]]==true){
			x[r[i]]=d[i]+x[l[i]];
			used[r[i]]=true;
		}else if(used[r[i]]==true){
			x[l[i]]=x[r[i]]-d[i];
			used[l[i]]=true;
		}else{
			x[l[i]]=0;
			x[r[i]]=d[0];
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}