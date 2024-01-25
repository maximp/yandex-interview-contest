#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	long int num = 0;
	cin >> num;

	if(num < 1)
		return 0;

	int curr = 0;
	cin >> curr;

	for(size_t n = 1; n < num; ++n)
	{
		int elem = 0;
		cin >> elem;
		if(elem != curr)
			cout << curr << endl;
		curr = elem;
	}

	cout << curr << endl;

	return 0;
}
