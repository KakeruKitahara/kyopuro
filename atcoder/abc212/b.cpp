#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;

int main()
{
  V a(4);
  int x;
  cin >> x;
  int j = 3;
  while (x != 0)
  {
    a[j] = x % 10;
    x /= 10;
    j--;
  }
  if (a[0] == a[1] && a[2] == a[1] && a[2] == a[3] && a[3] == a[0])
  {
    cout << "Weak" << endl;
    return 0;
  }
  else
  {
    int flag = 0;
    REP(i, 3)
    {
      if (a[i] + 1 == a[i + 1])
      {
        flag++;
      }
      else if (a[i] == 9 && a[i + 1] == 0)
      {
        flag++;
      }
    }
    if (flag == 3)
    {
      cout << "Weak" << endl;
      return 0;
    }
  }
  cout << "Strong" << endl;
  return 0;
}