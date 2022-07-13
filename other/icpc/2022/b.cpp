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

void solve(int n)
{
  VV a(n, V(2, -1));
  REP(i, n)
  {
    int b1, b2;
    cin >> b1 >> b2;
    if (b1 != b2)
    {
      a[i][0] = b1;
      a[i][1] = b2;
    }
  }

  deque<V> o;

  REP(i, n)
  {
    if (!(a[i][0] == -1 && a[i][1] == -1))
    {
      o.push_back(a[i]);
    }
  }
  int cnt = 0;
  while (o.size() != 0)
  {
    V pp = o.front();
    o.pop_front();
    V np = o.front();
    o.pop_front();
    int mins = IINF;
    sort(pp.begin(), pp.end());
    np.push_back(pp[0]);

    REP(i, np.size() - 1)
    {
      if (pp[0] == np[i])
      {
        np.erase(np.begin() + i);
        np.erase(np.end() - 1);
        break;
      }
    }

    pp.erase(pp.begin());
    cnt++;
    if (np.size() != 0)
    {
      o.push_front(np);
    }
    if (pp.size() != 0)
    {
      o.push_back(pp);
    }
  }

  cout << cnt << endl;
}

int main()
{
  while (1)
  {
    int a;
    cin >> a;
    if (a == 0)
    {
      break;
    }
    solve(a);
  }

  return 0;
}
