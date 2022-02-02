#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;
using S = string;
using ll = long long;

int main(){
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  REP(i, n){
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }
  REP(i, n)
  {
    cin >> c[i];
  }
  V num(100001, 0);
  ll ans = 0;

  REP(i, n){
    num[a[i]]++;
  }

  REP(j, n){
    ans += num[b[c[j] - 1]];
  }

  cout << ans <<endl;

}