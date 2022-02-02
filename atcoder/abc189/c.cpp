#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  V a(n);
  REP(i, n){
    cin >> a[i];
  }

  int ans = -1;
  int mins;

  REP(l, n){
    mins = 1E+6;
    REP2(r, l, n){
      mins = min(mins, a[r]);
      ans = max(ans, mins * (r - l + 1));
    }
  }

  cout << ans;
  return 0;
}