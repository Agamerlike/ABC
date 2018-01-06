#include <iostream>
 
using namespace std;
 
int main()
{
	long long N,A,B;
	long long X[100000];
	long long fatigue=0;
	cin >> N >> A >> B;
	for(int i=0;i<N;i++)
	{
		cin >> X[i];
	}
	
	for(int i=0;i<N-1;i++)
	{
		if(A*(X[i+1]-X[i]) > B)
		{
			fatigue += B;
		}else{
			fatigue += A*(X[i+1]-X[i]);
		}
	}
	
	cout << fatigue << endl;
	return 0;
}
