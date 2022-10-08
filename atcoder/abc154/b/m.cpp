#include <iostream>
#include<cstring>
using namespace std;

int main(){
	char ob[100];
	int len;

	cin >> ob;
	len = strlen(ob);
	for(int i = 0; i < len; i++){
		cout << "x";
	}
	cout << "\n";
	return 0;
}