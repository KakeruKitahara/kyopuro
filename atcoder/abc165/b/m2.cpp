#include <iostream>

using namespace std;

int main()
{
	int n;
	long long int i = 100;
	int cnt = 0;
	cin >> n;
	while (i < n)
	{
		i =(int)(i * 1.01); // この場合, i * 1.01の時に2桁増えてしまう (ex. 100(3桁) * 1.01 = 101.00(5桁))ので, 
												// 10^18の際, 20桁になり最大値を超えオーバーフローする.また, MAX18桁にするのもlonglong型を取らなくてはならない.
		cnt++;
	}
	cout << cnt;

	return 0;
}