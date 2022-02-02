#include <iostream>

using namespace std;

int main()
{
	int a, b, k;
	int flag = 0;
	cin >> k;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (i % k == 0)
		{
			cout << "OK";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "NG";
	}

	return 0;
}