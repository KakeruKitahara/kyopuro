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

vector<bool> Eratosthenes(int N)
{
  // テーブル
  vector<bool> isprime(N + 1, true);

  // 0, 1 は予めふるい落としておく
  isprime[0] = isprime[1] = false;

  // ふるい
  for (int p = 2; p <= N; ++p)
  {
    // すでに合成数であるものはスキップする
    if (!isprime[p])
      continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (int q = p * 2; q <= N; q += p)
    {
      isprime[q] = false;
    }
  }

  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}

int main()
{
  int n;
  cin >> n;
  vector<bool> pr = Eratosthenes(n);
  ll ans = 0;
  REP2(i, 1, n + 1)
  {
    if (pr[i] == false)
    {
      int a = i;
      // {{first, second}, {2, n_1}, {3, n_2}, {5, n_3}}のような配列を返す．
      vector<pair<long long, long long>> prime;
      for (long long ind = 2; ind * ind <= a; ind++)
      {
        if (a % ind != 0)
          continue;
        long long ex = 0;
        while (a % ind == 0)
        {
          ex++;
          a /= ind;
        }
        prime.push_back({ind, ex});
      }

      if (a != 1)
        prime.push_back({a, 1});

      ll fk = 1;
      REP(j, prime.size())
      {
        fk *= prime[j].second + 1;
      }

      ans += fk * i;
    }
    else
    {
      ans += 2 * i;
    }
  }

  cout << ans << endl;

  return 0;
}