#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <functional>
typedef long long ll;

using namespace std;

class Edge
{
	public:
	int year;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		year=c;
	}
};

vector<Edge> g[100000];
bool used[100000];
int y[100000];
pair<int,int> w[100000];

int df

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b>>y[i];
		a--;b--;
		g[a].push_back(Edge(b,y[i]));
		g[b].push_back(Edge(a,y[i]));
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
		cin>>w[i].first>>w[i].second;
	return 0;
}