#include <iostream>
using namespace std;

int main()
{
	string ob1, ob2, ob3;
	int n_ob1, n_ob2;

	cin >> ob1;
	cin >> ob2;
	cin >> n_ob1;
	cin >> n_ob2;
	cin >> ob3;

	if(ob1 == ob3){
		n_ob1--;
	}
	else if(ob2 == ob3){
		n_ob2--;
	}

	cout << n_ob1 << " " << n_ob2 << "\n";

	return 0;
}