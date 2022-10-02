#include <bits/stdc++.h>

using namespace std;

int main(){
	char str[100];
	char str2[100];
	int i = 0;

	cin >> str >> str2;

	while(str[i] != 0){
		if(str[i] != str2[i]){
			cout << "No";
			return 0;
		}
		i++;
	}
	cout << "Yes";

	return 0;
}