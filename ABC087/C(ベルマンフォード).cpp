#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

class Edge
{
	public:
	int cost;
	int next;

	Edge(int n,int c)
	{
		next=n;
		cost=c;
	}
};

vector<Edge> v[200];
int mind[200];

int main()
{
	for(int i=0;i<200;i++)
	{
		mind[i]=1000000;
	}
	mind[0]=0;
	int n,s;
	int ans;
	cin>>n;
	//1行目
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		if(i>0)
		{
			v[i-1].push_back(Edge(i,-1*c));
		}
		if(i==0)
		{
			s=c;
		}
	}
	//2行目
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		//cerr<<i%n<<endl;
		if(i>0)
		{
			v[n+i-1].push_back(Edge(n+i,-1*c));
		}
		v[i].push_back(Edge(n+i,-1*c));
	}

	//ベルマンフォード
	for(int i=0;i<n*2;i++)
	{
		for(int j=0;j<2*n;j++)
		{
			for(int k=0;k<v[j].size();k++)
			{
				Edge e = v[j][k];
				if(mind[j] != 1000000 && mind[e.next] > mind[j]+e.cost)
				{
					mind[e.next] = mind[j]+e.cost;
					if(i==2*n-1)
					{
						//負閉路の存在
						//このプログラムでは空白
						cerr<<"minus loop"<<endl;
					}
				}
			}
		}
	}

	ans = -1*mind[2*n-1];
	ans += s;
	cout<<ans<<endl;
	return 0;
}