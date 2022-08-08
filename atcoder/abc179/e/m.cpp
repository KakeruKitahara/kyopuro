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
  ll n;
  int x, m;

  cin >> n >> x >> m;

  V dp(m, -1);
  V lp;
  ll now = x;
  ll sum = 0;

  while (n != 0)
  {
    lp.push_back(now);
    sum += now;
    dp[now] = 1;
    now = (now * now) % m;
    n--;
    if (dp[(now * now) % m] == 1)
    {
      lp.push_back(now);
      sum += now;
      dp[now] = 1;
      now = (now * now) % m;
      n--;
      break;
    }
  };

  ll pu = 0;
  int en = 0;
  int j = lp.size();
  REP(i, lp.size())
  {
    if (now == lp[i])
    {
      pu = n / (lp.size() - i);
      en = n % (lp.size() - i);
      j = i;
      break;
    }
  }
  ll lsum = 0;
  ll ensum = 0;
  int st = j;
  for (j; j < lp.size(); j++)
  {
    lsum += lp[j];
    if (j < en + st)
    {
      ensum += lp[j];
    }
  }

  cout << sum + lsum * pu + ensum << endl;

  return 0;
}