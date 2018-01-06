#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	int flag=1;
	cin >> str;
	string dream = "maerd";
	string dreamer = "remaerd";
	string erase = "esare";
	string eraser = "resare";
	reverse(begin(str),end(str));
	while(flag!=0)
	{
		flag = 0;
		if(dream==str.substr(0,5))
		{
			str.replace(0,5,"");
			flag = 1;
		}
		if(dreamer==str.substr(0,7))
		{
			str.replace(0,7,"");
			flag = 1;
		}
		if(erase==str.substr(0,5))
		{
			str.replace(0,5,"");
			flag = 1;
		}
		if(eraser==str.substr(0,6))
		{
			str.replace(0,6,"");
			flag = 1;
		}
	}
	if(str=="")
	{
		cout << "YES" <<endl;
	}else{
		cout << "NO" <<endl;
	}
	return 0;
}