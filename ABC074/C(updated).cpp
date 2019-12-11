#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a,b,c,d,e,f;
	int water;
	int sugar;
	double pmax=0;//濃度の最大値
	double psup=0;
	pair<int,int> sw;//濃度最大時の水と砂糖の量
	cin>>a>>b>>c>>d>>e>>f;
	psup = (double)e/(double)(100+e);
	a*=100;
	b*=100;
	sw=make_pair(a,0);
	for(int i=0;i<f/a+1;i++)
	{
		for(int j=0;j<f/b+1;j++)
		{
			water=a*i+b*j;
			for(int x=0;x<(f-water)/c+1;x++)
			{
				for(int y=0;y<(f-water)/d+1;y++)
				{
					sugar=c*x+d*y;
					if(water>0 && water+sugar<=f)
					{
						double p=(double)sugar/(double)(sugar+water);
						if(p>pmax && p<=psup)
						{
							pmax=p;
							sw = make_pair(water,sugar);
						}
					}
				}
			}
		}
	}
	cout<<sw.first+sw.second<<" "<<sw.second<<endl;
	return 0;
}