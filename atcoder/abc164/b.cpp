#include <iostream>
using namespace std;

int main()
{
	int t[2], a[2];
	cin >> t[0] >> t[1] >> a[0] >> a[1];
	while (1)
	{
		a[0] -= t[1];
		if (a[0] <= 0)
		{
			break;
		}
		t[0] -= a[1];
		if (t[0] <= 0)
		{
			break;
		}
	}
	if (a[0] <= 0)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}