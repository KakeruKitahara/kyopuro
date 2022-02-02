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
constexpr int INF = 1000000000 + 8;

int main()
{
  int n, k;
  cin >> n >> k;
  V a(n), b(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }

  ll cnt = 0;
  REP(i, n)
  {
    cnt += abs(a[i] - b[i]);
  }

  if (k >= cnt && cnt % 2 == k % 2)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}