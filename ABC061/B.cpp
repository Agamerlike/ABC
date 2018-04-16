#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
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

vector<Edge> g[50];
bool used[50];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}

	for(int i=0;i<n;i++)
		cout<<g[i].size()<<endl;
	return 0;
}