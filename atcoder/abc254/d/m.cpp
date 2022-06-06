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
using S = string;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
using mint = modint1000000007;

vector<P> prime(int N)
{
  vector<P> res;

  for (int p = 2; p * p <= N; ++p)
  {
    if (N % p != 0)
    {
      continue;
    }
    int e = 0;
    while (N % p == 0)
    {
      ++e;
      N /= p;
    }
    res.emplace_back(p, e);
  }

  if (N != 1)
  {
    res.emplace_back(N, 1);
  }
  return res;
}

int main()
{
  int n;
  cin >> n;

  int ans = 0;

  REP2(i, 1, n + 1)
  {

    vector<P> s = prime(i);
    int a = 1;
    REP(i, s.size()){
      if(s[i].second % 2 == 1){
        a *= s[i].first;
      }
    }

    ans += sqrt(n / a);
  }

  cout << ans << endl;

  return 0;
}