#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dpw[3000];
int dps[3000];
int a,b,c,d,e,f;
float pmax=0;//濃度の最大
pair<int,int> maxindex;

int fullwater(int now,bool af)
{
	if(af==true)
	{
		if(now+a<=f)
		{
			dpw[now+a]=1;
			fullwater(now+a,true);
			fullwater(now+a,false);
		}
	}else{
		if(now+b<=f)
		{
			dpw[now+b]=1;
			fullwater(now+b,true);
			fullwater(now+b,false);
		}
	}
	return 0;
}

int fullsugar(int now,bool cf)
{
	cerr<<now<<endl;
	if(cf==true)
	{
		if(now+c<=f)
		{
			dps[now+c]=1;
			fullsugar(now+c,true);
			fullsugar(now+c,false);
		}
	}else{
		if(now+d<=f)
		{
			dps[now+d]=1;
			fullsugar(now+d,true);
			fullsugar(now+d,false);
		}
	}
	return 0;
}

int main()
{
	int sugar,water;
	float maxn=0;
	fill(dpw,dpw+3000,-1);
	fill(dps,dps+3000,-1);
	maxindex = make_pair(0,0);
	cin>>a>>b>>c>>d>>e>>f;
	a*=100;
	b*=100;
	dps[0]=1;
	fullwater(0,true);
	fullwater(0,false);
	fullsugar(0,true);
	fullsugar(0,false);
	for(int i=0;i<=f;i++)
	{
		if(dpw[i]<0)
			continue;
		for(int j=0;j<=f;j++)
		{
			if(dps[j]<0)
				continue;
			float noudo = (float)(100*j/(i+j));
			if(noudo <= e && i+j <= f&& noudo > maxn)
			{
				maxn = noudo;
				maxindex.first=i+j;
				maxindex.second=j;
			}
		}
	}
	cout<<maxindex.first<<" "<<maxindex.second<<endl;
	return 0;
}