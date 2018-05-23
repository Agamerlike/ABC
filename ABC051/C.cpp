#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	int sx,sy,tx,ty;
	int ans=0;
	
	cin>>sx>>sy>>tx>>ty;
	//s->t
	int yoko=tx-sx;
	int tate=ty-sy;
	for(int i=0;i<yoko;i++)
		cout<<'R';
	for(int i=0;i<tate;i++)
		cout<<'U';
	//t->s
	for(int i=0;i<yoko;i++)
		cout<<'L';
	for(int i=0;i<tate;i++)
		cout<<'D';
	//s->t(2回目)
	cout<<'D';//ずらす
	for(int i=0;i<yoko+1;i++)
		cout<<'R';
	for(int i=0;i<tate+1;i++)
		cout<<'U';
	cout<<'L';
	//t->s(2回目)
	cout<<'U';
	for(int i=0;i<yoko+1;i++)
		cout<<'L';
	for(int i=0;i<tate+1;i++)
		cout<<'D';
	cout<<'R'<<endl;
	return 0;
}