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
constexpr int INF = 1000000000 + 8;
using mint = modint1000000007;

// エラトステネスの篩
vector<bool> Eratosthenes(int n)
{
  vector<bool> isPrime(n + 1, true);

  for (int i = 0; i <= 2; i++)
  {
    isPrime[i] = true;
  }

  for (int i = 2; i < n; i++)
  {
    //合成数は既に探索済みなのでskip.
    if (!isPrime[i])
      continue;

    // 以下のfor文でふるいにかけている.
    // i*2から開始してiごと足しているのでjは全て合成数である．
    // 計算量は素数の逆数和なので調和級数よりも抑えることが出来てloglognとなる．
    for (int j = i * 2; j < n; j += i)
    {
      isPrime[j] = false;
    }
  }
  return isPrime;
}

int main()
{
  int l, r;
  cout << "範囲を選択(l:r) : ";
  cin >> l >> r;

  vector<bool> ans = Eratosthenes(r);

  REP2(i, l, r + 1)
  {
    if (ans[i] == true)
    {
      cout << i << endl;
    }
  }

  return 0;
}