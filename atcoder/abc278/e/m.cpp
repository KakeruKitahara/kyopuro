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
  int h, w, n, h2, w2;
  cin >> h >> w >> n >> h2 >> w2;

  VV a(h, V(w));
  map<int, int> cnt, tmp;

  REP(i, h)
  {
    REP(j, w)
    {
      cin >> a[i][j];
      cnt[a[i][j]]++;
    }
  }

  tmp = cnt;

  REP(i, h - h2 + 1)
  {
    cnt = tmp;

    REP2(k, i, h2 + i)
    {
      REP(j, w2)
      {
        cnt[a[k][j]]--;
        if (cnt[a[k][j]] == 0)
        {
          cnt.erase(a[k][j]);
        }
      }
    }

    cout << cnt.size();

    if (w == w2)
    {
      cout << endl;
    }
    else
    {
      cout << " ";
    }

    REP(j, w - w2)
    {
      REP2(k, i, h2 + i)
      {
        cnt[a[k][j]]++;
        cnt[a[k][j + w2]]--;
        if (cnt[a[k][j + w2]] == 0)
        {
          cnt.erase(a[k][j + w2]);
        }
      }
      cout << cnt.size() << " ";
    }
    cout << endl;
  }

  return 0;
}