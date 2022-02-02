#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, a, n) for (int i = a; i < n; i++)
#define P pair<int, int>
using namespace std;

int main(){
	int n;
	int cnt = 0;
	cin >> n;
	string s[n];

	rep(i, n)cin >> s[i];
	sort(s, s+n);
	rep(i, n)if(s[i] != s[i+1])cnt++;

	cout << cnt;
	return 0;
}
