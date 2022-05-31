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
int pow(int a, int b)
{
  int sum = 1;
  REP(i, b)
  {
    sum *= a;
  }

  return sum;
}

int main()
{
  int a, n;
  cin >> a >> n;
  int x = 1;
  map<ll, int> cnt;

  int n2 = n;
  int c2 = 0;

  while (n2 != 0)
  {
    c2++;
    n2 /= 10;
  }

  queue<tuple<int, int, int>> q;
  tuple<int, int, int> ans = make_tuple(-1, -1, -1);
  q.push(make_tuple(0, x, -1));

  while (q.size() != 0)
  {
    tuple<int, int, int> ptr = q.front();
    q.pop();

    if (get<1>(ptr) == n)
    {
      ans = ptr;
      break;
    }

    int pp = get<1>(ptr);
    int c = 0;
    while (pp != 0)
    {
      c++;
      pp /= 10;
    }

    if (c2 >= c)
    {
      q.push(make_tuple(get<0>(ptr) + 1, get<1>(ptr) * a, 0));
      cnt[get<1>(ptr)] = 1;
    }
    int d = get<1>(ptr) % 10;
    if (d != 0)
    {
      get<1>(ptr) = get<1>(ptr) / 10 + pow(10, c - 1) * d;
      if (cnt.count(get<1>(ptr)) == 0)
      {
        q.push(make_tuple(get<0>(ptr) + 1, get<1>(ptr), 1));
        cnt[get<1>(ptr)] = 1;
      }
    }
  }

  cout << get<0>(ans) << endl;

  return 0;
}