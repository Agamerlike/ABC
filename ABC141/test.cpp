#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include <random>
using namespace std;


int main()
{
	int n;
	random_device rnd;
	cin>>n;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		char a=rnd()%2+'c';
		//a='r';
		cout<<a;
	}
	cout<<endl;
}