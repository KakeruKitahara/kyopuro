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
  int n, m;
  cin >> n >> m;
  VV a(m);
  V k(m);
  REP(i, m)
  {
    cin >> k[i];
    a[i].resize(k[i]);
    REP(j, k[i])
    {
      cin >> a[i][j];
    }
  }

  REP2(i, 1, n + 1)
  {
    REP2(i2, i + 1, n + 1)
    {
      int p = 0;
      REP(j, m)
      {
        int f = 0;
        REP(l, k[j])
        {
          if (a[j][l] == i)
          {
            f++;
          }
          else if (a[j][l] == i2)
          {
            f++;
          }
        }

        if(f == 2){
          p = 1;
          break;
        }
      }

      if(p == 0){
        cout << "No" << endl;
        return 0;
      }
    }
  }


  cout << "Yes" << endl;
  

  return 0;
}