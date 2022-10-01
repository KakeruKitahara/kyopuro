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

  ll n, k;
  cin >> n >> k;
  Vl a(n);
  REP(i, n)
  {
    cin >> a[i];
  }

  vector<pair<ll, int>> b(n);

  REP(i, n)
  {
    b[i].first = a[i];
    b[i].second = i;
  }

  sort(b.begin(), b.end());

  Vl sa(n);
  sa[0] = b[0].first;
  REP(i, n - 1)
  {
    sa[i + 1] = b[i + 1].first - b[i].first;
  }

  ll sum = 0;
  ll sasa = 0;
  int i = 0;
  for (i = 0; i < n; i++)
  {
    sum += sa[i] * (n - i);
    sasa += sa[i];
    if (k < sum)
    {
      break;
    }
  }

  sasa -= sa[i];
  sum -= sa[i] * (n - i);

int c = 1;
  if(i == 0 || sa[i - 1] == 0){
    c--;
  }

  ll wa = (k - sum) / (n - i + c);
  ll ama = (k - sum) % (n - i + c);

  REP(j, i)
  {
    a[b[j].second] = 0;
  }

  REP(j, n)
  {
    if (a[j] > 0)
    {
      a[j] -= sasa + wa;
    }
  }
  int cnt = 0;
  int ii = 0;
  while (cnt != ama)
  {
    if (a[ii] > 0)
    {
      {
        a[ii]--;
        cnt++;
      }
    }
    ii++;
  }

  REP(j, n)
  {
    cout << a[j] << " ";
  }
  cout << endl;

  return 0;
}