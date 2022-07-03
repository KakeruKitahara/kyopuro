#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using Vl = vector<long long>;
using VV = vector<vector<int>>;
using VVl = vector<vector<long long>>;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

void solve(int a)
{
  int num = a;
  // {{first, second}, {2, n_1}, {3, n_2}, {5, n_3}}のような配列を返す．
  set<int> prime;
  for (long long ind = 2; ind <= a; ind++)
  {
    if (a % ind != 0 || (ind % 7 != 1 && ind % 7 != 6))
      continue;
    if ((a / ind) % 7 == 1 || (a / ind) % 7 == 6)
    {
      prime.insert(ind);
      prime.insert(a / ind);
    }
  }

  V jd(prime.size());
  int c = 0;
  for (int k : prime)
  {
    for (long long ind = 2; ind < k; ind++)
    {
      if (k % ind != 0 || (ind % 7 != 1 && ind % 7 != 6))
        continue;
      if ((k / ind) % 7 == 1 || (k / ind) % 7 == 6)
      {
        jd[c] = 1;
      }
    }
    c++;
  }

  cout << num << ":";
  c = 0;
  for (int k : prime)
  {
    if (jd[c] == 0 && 0 < c)
      cout << " " << k;
    c++;
  }
  cout << endl;
}

int main()
{
  while (1)
  {
    int a;
    cin >> a;
    if (a == 1)
    {
      break;
    }
    solve(a);
  }

  return 0;
}