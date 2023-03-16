#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/* macro */
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using Vl = vector<long long>;
using VVl = vector<vector<long long>>;
using VVVl = vector<vector<vector<long long>>>;
using P = pair<int, int>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

/* pair operator */
template <class X>
pair<X, X> operator+(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first + ob2.first;
  res.second = ob1.second + ob2.second;
  return res;
}

template <class X>
pair<X, X> operator-(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first - ob2.first;
  res.second = ob1.second - ob2.second;
  return res;
}

template <class X>
pair<X, X> operator*(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first * ob2.first;
  res.second = ob1.second * ob2.second;
  return res;
}

template <class X>
pair<X, X> operator/(pair<X, X> &ob1, pair<X, X> &ob2)
{
  pair<X, X> res;
  res.first = ob1.first / ob2.first;
  res.second = ob1.second / ob2.second;
  return res;
}

int main()
{
  int n, k;
  cin >> n >> k;
  S s;
  cin >> s;
  S t;
  t.push_back(s[0]);
  int d = 0;
  int ans = 0;
  REP(i, n - 1)
  {

    if (s[i] != s[i + 1])
    {
      t.push_back(s[i + 1]);
      ans += d;
      d = 0;
    }
    else
    {
      d++;
    }
  }
  ans += d;

  int tmp = 0;
  REP(i, t.size())
  {
    if (t[i] == 'L')
    {
      tmp++;
    }
  }
  int l = 0;
  if (tmp * 2 <= t.size())
  {
    l = 1;
  }
  else{
    tmp = t.size() - tmp;
  }

  S lr = "RL";

  int cnt = 0;
  if (t[0] == lr[l])
  {
    cnt++;
  }
  if (t.back() == lr[l])
  {
    cnt++;
  }

  int dd = min(k, tmp - cnt);

  ans += dd * 2;

  k -= dd;

  REP(j, cnt)
  {
    if (k > 0)
    {
      ans++;
    }
    k--;
  }

  cout << ans << endl;

  return 0;
}