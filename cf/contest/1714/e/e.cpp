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

void solve()
{
  int n;
  cin >> n;
  V a(n);
  int f5 = 0, f10 = 0, f15 = 0;
  int c5, c10;
  REP(i, n)
  {
    cin >> a[i];
    if (a[i] % 10 == 0)
    {
      f10 = 1;
      c10 = a[i];
    }
    if (a[i] % 10 == 5)
    {
      f5 = 1;
      c5 = a[i];
    }
  }
  if (f10 == 1 && f5 == 1)
  {
    f5 = 0;
    f10 = 0;
    f15 = 1;
  }

  if (f5 == 1)
  {
    REP(i, n)
    {
      if (a[i] % 10 != 5)
      {
        cout << "No" << endl;
        return;
      }
      else
      {
        if (c5 != a[i])
        {
          cout << "No" << endl;
          return;
        }
      }
    }
    cout << "Yes" << endl;
    return;
  }

  if (f10 == 1)
  {
    REP(i, n)
    {
      if (a[i] % 10 != 0)
      {
        cout << "No" << endl;
        return;
      }
      else
      {
        if (c10 != a[i])
        {
          cout << "No" << endl;
          return;
        }
      }
    }
    cout << "Yes" << endl;
    return;
  }

  if (f15 == 1)
  {
    REP(i, n)
    {
      if (a[i] % 10 == 5)
      {
        int t = a[i] + (a[i] % 10);
        if (t != c10)
        {
          cout << "No" << endl;
          return;
        }
      }
      else if (a[i] % 10 == 0)
      {
        if (c10 != a[i])
        {
          cout << "No" << endl;
          return;
        }
      }
      else
      {
        cout << "No" << endl;
        return;
      }
    }
    cout << "Yes" << endl;
    return;
  }
  V sa, sb;
  REP(i, n)
  {
    int t = a[i];
    if (t % 2 == 1)
    {
      t = t + (t % 10);
    }
    int f100 = 0, f6 = 0;
    if ((t / 10) % 2 == 1)
    {
      f100 = 1;
    }
    if (t % 10 == 6)
    {
      f6 = 1;
    }

    if ((f100 == 1 && f6 == 0) || (f100 == 0 && f6 == 1))
    {
      sa.push_back(t);
    }
    else
    {
      sb.push_back(t);
    }
  }

  if (sa.size() > 0 && sb.size() > 0)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
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