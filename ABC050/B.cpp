#include <iostream>

using namespace std;

int main()
{
	int N;
	int t[100];
	int M;
	int px[100][2];

	int time=0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> t[i];
	}
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> px[i][0] >> px[i][1];
	}

	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if((px[i][0]-1)==j)
			{
				time += px[i][1];
			}else{
				time += t[j];
			}
		}
		cout << time <<endl;
		time =0;
	}
	return 0;
}