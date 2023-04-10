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

  int n;
  cin >> n;

  V d = {3, 5, 7};

  V dd;

  REP(i, 3)
  {
    REP(j, 3)
    {
      REP(k, 3)
      {

        dd.push_back(d[i] * 100 + d[j] * 10 + d[k]);
      }
    }
  }

  REP(i, 3)
  {
    REP(j, 3)
    {
      REP(k, 3)
      {
        REP(l, 3)
        {
          dd.push_back(d[i] * 1000 + d[j] * 100 + 10 * d[k] + d[l]);
        }
      }
    }
  }

  REP(i, 3)
  {
    REP(j, 3)
    {
      REP(k, 3)
      {
        REP(l, 3)
        {
          REP(m, 3)
          {
            dd.push_back(d[i] * 10000 + d[j] * 1000 + 100 * d[k] + 10 * d[l] + d[m]);
          }
        }
      }
    }
  }

  sort(dd.begin(), dd.end());
  int ans = 0;
  REP(i, n)
  {
    int f = 0;

    REP(j, dd.size())
    {
      ll num = i * 100000 + dd[j];
      if (n < num)
      {
        f = 1;
        break;
      }
      V nc(10);
      while (num != 0)
      {
        nc[num % 10]++;
        num /= 10;
      }
      int cnt = 0;
      REP(k, 10)
      {
        if (k == 3 || k == 5 || k == 7)
        {
          if (nc[k] > 0)
          {
            cnt++;
          }
        }
        else
        {
          if (nc[k] == 0)
          {
            cnt++;
          }
        }
      }
      if (cnt == 10)
      {
        ans++;
      }
    }

    if (f == 1)
    {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}