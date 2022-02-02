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
  int t, tmp;
  cin >> t;
  P lr[t];
  REP(i, t)cin >> lr[i].first >> lr[i].second;
  int ans[t];

  REP(i, t){
    ans[i] = lr[i].second - lr[i].first*2 + 1;
    tmp = lr[i].second / 2 - lr[i].first / 2 ;
    ans[i]*= 2;
    ans[i] -= tmp;
  }

  REP(i, t)cout << ans[i] << "\n";

  return 0;

}