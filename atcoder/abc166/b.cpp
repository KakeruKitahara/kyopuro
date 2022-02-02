#include <bits/stdc++.h>

using namespace std;
#define N 200

int main()
{
	int n, k;
	int d[N];
	int a[N][N];
	int cnt[N] = {};
	int flag = 0;

	cin >> n >> k;
	for (int i = 0; i < k; i++){
		cin >> d[i];
				for(int j = 0; j < d[i]; j++){
			cin >> a[i][j];
			cnt [a[i][j]]++;
		}
	}
	for(int i =1; i<=n; i++){
		if(cnt[i] == 0){
			flag++;
		}
	}
	cout << flag;
		return 0;
}