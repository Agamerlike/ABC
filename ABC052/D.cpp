#include <iostream>

using namespace std;

int main()
{
	int N,A,B;
	int X[100000];
	int fatigue=0;
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