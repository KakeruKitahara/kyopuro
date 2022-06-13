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

vector<long long> calc_divisors(long long N)
{
  // 答えを表す集合
  vector<long long> res;

  // 各整数 i が N の約数かどうかを調べる
  for (long long i = 1; i * i <= N; ++i)
  {
    // i が N の約数でない場合はスキップ
    if (N % i != 0)
      continue;

    // i は約数である
    res.push_back(i);

    // N ÷ i も約数である (重複に注意)
    if (N / i != i)
      res.push_back(N / i);
  }

  // 約数を小さい順に並び替えて出力
  sort(res.begin(), res.end());
  return res;
}

int main()
{
  ll k;
  cin >> k;
  ll ans = 0;

  vector<long long> div = calc_divisors(k);
  REP(i, div.size())
  {
    vector<long long> div2 = calc_divisors(k / div[i]);
    auto it = lower_bound(div2.begin(), div2.end(), div2[i]);
    int s = it - div2.begin();
    /* left + 1 ~ right - 1を探索するが，
    これが偶数のみやsの倍数のみなど，数値が飛んでいる数直線上でおこなうとき，
    if文のmidをmid * s としてansの代入数値をright * sとする．このとき捜索範囲が1/sとなる．*/

    int left = 0, right = div2.size();

    while (right - left > 1)
    {
      int mid = left + (right - left) / 2;
      if (div2[mid] / div[i] >= 0) // f(mid)の値とkeyを比較してkey以上だったらac
        right = mid;                 // ac
      else
        left = mid; // wa
    }
    int ind = right; // ansがacを満たす最小値となる．

    ans += div2[ind - 1] - s;
  }

  cout << ans << endl;

  return 0;
}