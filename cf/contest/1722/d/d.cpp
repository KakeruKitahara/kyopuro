#include <bits/stdc++.h>
using namespace std;

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

/* Euclid  */
template <class X>
X gcd(X a, X b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

/* pow  */
template <class X>
X pow(X x, X n)
{
  X ret = 1;
  while (n > 0)
  {
    if (n & 1)
      ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

/* fenick tree */
class fenick
{
  vector<ll> bit;
  fenick(int n)
  {
    bit.resize(n);
  }

public:
  void add(int i, ll x)
  {
    i++;
    for (int idx = i; idx <= bit.size(); idx += (idx & -idx))
    {
      bit[idx - 1] += x;
    }
  }

  ll sum(int i)
  {
    ll ans = 0;
    for (int idx = i; idx > 0; idx -= (idx & -idx))
    {
      ans += bit[idx - 1];
    }
    return ans;
  }

  ll sum(int a, int b)
  {
    return sum(b) - sum(a - 1);
  }
};

void solve()
{
  int n;
  cin >> n;
  S s;
  cin >> s;
  ll sum = 0;
  REP(i, n)
  {
    if (s[i] == 'L')
    {
      sum += i;
    }
    else
    {
      sum += n - i - 1;
    }
  }
  ll tr = sum;
  int cnt = 0;
  Vl ans(n + 1, sum);
  REP(i, n / 2)
  {
    if (s[i] == 'L')
    {
      sum += n - 2 * i - 1;
      cnt++;
    }
    ans[cnt] = max(sum, ans[cnt]);
    if (s[n - i - 1] == 'R')
    {
      sum += n - 2 * i - 1;
      cnt++;
    }

    ans[cnt] = max(sum, ans[cnt]);
  }

  REP2(i, 1, n + 1)
  {
    tr = max(ans[i], tr);
    cout << tr << " ";
  }
  cout << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(i, t)
  {
    solve();
  }
  return 0;
}