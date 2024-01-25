#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string j, s;
	getline(cin, j);
	getline(cin, s);

	size_t num = 0;
	for(char c : s)
	{
		if(j.find(c) != string::npos)
			++num;
	}
	cout << num;
}
