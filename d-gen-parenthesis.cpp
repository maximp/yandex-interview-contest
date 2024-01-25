#include <iostream>
#include <string>

using namespace std;

void gen(int n, int counter_open, int counter_close, string ans)
{
	if(counter_open + counter_close == 2 * n)
	{
		cout << ans << endl;
		return;
	}
	if(counter_open < n)
		gen(n, counter_open + 1, counter_close, ans + '(');
	if(counter_open > counter_close)
		gen(n, counter_open, counter_close + 1, ans + ')');
}

int main()
{
	int n = 0;
	cin >> n;
	gen(n, 0, 0, "");
	return 0;
}
