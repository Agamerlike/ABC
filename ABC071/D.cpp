#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;

using namespace std;

ll MOD=1000000007;

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

vector<Edge> g[52];
map<string,int> c;

int main()
{
	int n;
	int v=0;
	ll ans=1;
	bool tate;
	string s[2];
	cin>>n;
	cin>>s[0];
	cin>>s[1];
	for(int i=0;i<n;i++)
	{
		//tate
		if(s[0][i]==s[1][i])
		{
			g[v].push_back(Edge(v+1,1));
			g[v].push_back(Edge(v+2,1));
			v++;
		}else{
			g[v].push_back(Edge(v+1,1));
			g[v].push_back(Edge(v+2,1));
			g[v+1].push_back(Edge(v+2,1));
			v+=2;
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}