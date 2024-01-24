#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	long int num = 0;
	cin >> num;

	size_t maxbits = 0, bits = 0;
	for(size_t n = 0; n < num; ++n)
    {
        int elem = 0;
        cin >> elem;
        if(elem == 1) {
            ++bits;
            maxbits = bits > maxbits ? bits : maxbits;
        } else if (elem == 0) {
            bits = 0;
        }

    }

    cout << maxbits;

	return 0;
}
