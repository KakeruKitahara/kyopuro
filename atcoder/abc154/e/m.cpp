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
template <typename T>
class Fenick
{
  vector<T> bit;

public:
  Fenick(int n)
  {
    bit.resize(n);
  }

  void add(int i, T x)
  {
    for (int idx = i + 1; idx <= bit.size(); idx += idx & (-idx))
    {
      bit[idx - 1] += x;
    }
  }

  T sum(int i)
  {
    T ans = 0;
    for (int idx = i + 1; idx > 0; idx -= idx & (-idx))
    {
      ans += bit[idx - 1];
    }
    return ans;
  }

  T sum(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }
};

int main()
{
  S s;
  int k;
  cin >> s >> k;

  ll ans = 0;

  if (k == 3)
  {
    REP(a1, s.size())
    {
      REP2(a2, a1 + 1, s.size())
      {
        REP2(a3, a2 + 1, s.size())
        {
          int b1 = s[a1] - '0';
          int b2 = s[a2] - '0';
          int b3 = s[a3] - '0';

          int t = b1 * 100 + b2 * 10 + b3;

          int f = 0;

          if (a1 == 0 && a2 == 1 && a3 == 2)
          {
            ans += max(b1 - 1, 0) * 9 * 9 + max(b2 - 1, 0) * 9 + b3;
          }
          else if (a1 == 0 && a2 == 1)
          {

            REP2(i, 2, a3)
            {
              if (s[i] != '0')
              {
                f = 1;
                break;
              }
            }

            if (f == 1)
            {
              ans += max(b1 - 1, 0) * 9 * 9 + b2 * 9;
            }
            else
            {
              if (t < 111)
              {
                continue;
              }
              ans += max(b1 - 1, 0) * 9 * 9 + max(b2 - 1, 0) * 9 + b3;
            }
          }
          else if (a1 == 0)
          {

            REP2(i, 1, a2)
            {
              if (s[i] != '0')
              {
                f = 1;
                break;
              }
            }

            if (f == 1)
            {
              ans += b1 * 9 * 9;
            }
            else
            {
              if (t < 111)
              {
                continue;
              }
              ans += max(b1 - 1, 0) * 9 * 9 + b2 * 9;
            }
          }
          else
          {
            ans += 729;
          }
        }
      }
    }
  }
  else if (k == 2)
  {
    REP(a1, s.size())
    {
      REP2(a2, a1 + 1, s.size())
      {

        int b1 = s[a1] - '0';
        int b2 = s[a2] - '0';

        if (a1 == 0 && a2 == 1)
        {
          ans += max(b1 - 1, 0) * 9 + b2;
        }
        else if (a1 == 0)
        {
          int f = 0;
          REP2(i, 1, a2)
          {
            if (s[i] != '0')
            {
              f = 1;
              break;
            }
          }

          if (f == 1)
          {
            ans += b1 * 9;
          }
          else
          {
            ans += max(b1 - 1, 0) * 9 + b2;
          }
        }
        else
        {
          ans += 81;
        }
      }
    }
  }
  else
  {
    REP(a1, s.size())
    {

      if (a1 == 0)
      {
        int b1 = s[a1] - '0';
        ans += b1;
      }
      else
      {
        ans += 9;
      }
    }
  }

  cout << ans << endl;

  return 0;
}