#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> a(n); // longlongにしないとオーバーフロー.
  REP(i, n)
  {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  ll sum = 0; // a(n)をllにするなら, その総和もllにする.
  ll add = 0; // 以下同文. 忘れない.
  REP(i, n){
    add += a[i];
  }
  REP(i, n)
  {
    add -= a[i];
    sum += (n - 1 - i) * a[i] - add;
  }

  cout << sum << endl;

  return 0;
}
