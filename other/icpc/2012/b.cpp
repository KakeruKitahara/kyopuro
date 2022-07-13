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

void solve(int a, int l)
{

  V s(21);
  s[0] = a;
  REP2(i, 1, 21)
  {
    int tmp = s[i - 1];
    V num(l);
    REP(j, l)
    {
      num[j] = tmp % 10;
      tmp /= 10;
    }
    sort(num.begin(), num.end());
    int maxa = 0, mina = 0;
    REP(j, l)
    {
      if (l - num.size() <= j)
      {
        mina += num[j];
      }
      if (j != l - 1)
      {
        mina *= 10;
      }
    }
    reverse(num.begin(), num.end());
    REP(j, l)
    {
      if (j < num.size())
      {
        maxa += num[j];
      }
      if (j != l - 1)
      {
        maxa *= 10;
      }
    }
    s[i] = maxa - mina;
  }

  REP(i, s.size())
  {
    REP2(j, i + 1, s.size())
    {
      if (s[i] == s[j])
      {
        cout << i << " " << s[i] << " " << j - i << endl;
        return;
      }
    }
  }
}

int main()
{
  while (1)
  {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
    {
      break;
    }
    solve(a, b);
  }

  return 0;
}
