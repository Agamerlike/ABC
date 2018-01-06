#include <iostream>

using namespace std;

int main()
{
	int N;
	int x = 0;
	int max = 0;
	char s[100];
	cin >> N;
	cin >> s;
	
	for(int i=0;i<N;i++)
	{
		if(s[i]=='I')
		{
			x++;
		}else if(s[i]=='D'){
			x--;
		}

		if(x>max)
		{
			max = x;
		}
	}
	cout << max << endl;
	return 0;
}