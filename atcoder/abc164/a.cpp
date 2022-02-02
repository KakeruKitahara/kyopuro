#include <iostream>
using namespace std;

int main()
{

	int w, s;

	cin >> s >> w;
	if (w >= s)
	{
		cout << "unsafe\n";
	}
	else
	{
		cout << "safe\n";
	}
	return 0;
}