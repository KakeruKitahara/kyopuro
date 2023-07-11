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
using Pl = pair<long long, long long>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;
using mint = modint1000000007;

/* change function */
template <class X>
void chmin(X &a, X b) { a = min(a, b); }
template <class X>
void chmax(X &a, X b) { a = max(a, b); }

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

/* dikstra */
void dijkstra(VVP graph, int s, Vl &dis)
{
  dis.resize(graph.size(), LINF);
  priority_queue<Pl, vector<Pl>, greater<Pl>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty())
  {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first)
    {
      continue;
    }
    for (auto &e : graph[v])
    { // first : to, second : cost
      if (dis[e.first] > dis[v] + e.second)
      {
        dis[e.first] = dis[v] + e.second;
        pq.emplace(dis[e.first], e.first);
      }
    }
  }
}

void dijkstra(VVP graph, int s, Vl dis, V &prev)
{
  dis.resize(graph.size(), LINF);
  prev.resize(graph.size(), -1);
  priority_queue<Pl, vector<Pl>, greater<Pl>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty())
  {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first)
    {
      continue;
    }
    for (auto &e : graph[v])
    {
      if (dis[e.first] > dis[v] + e.second)
      {
        dis[e.first] = dis[v] + e.second;
        prev[e.first] = v;
        pq.emplace(dis[e.first], e.second);
      }
    }
  }
}

V get_dikstra_path(const V prev, int t)
{
  V path;
  for (int cur = t; cur != -1; cur = prev[cur])
  {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());
  return path;
}

/* divisor */
vector<bool> eratosthenes(int N)
{
  vector<bool> isprime(N + 1, true);

  isprime[0] = isprime[1] = false;

  for (int p = 2; p <= N; ++p)
  {
    if (!isprime[p]) // しなくてもO(nlogn)
      continue;
    for (int q = p * 2; q <= N; q += p)
    {
      isprime[q] = false;
    }
  }

  return isprime;
}

vector<Pl> factorize(ll N)
{
  vector<Pl> res;

  for (long long p = 2; p * p <= N; ++p)
  {
    if (N % p != 0)
    {
      continue;
    }

    int e = 0;
    while (N % p == 0)
    {
      ++e;
      N /= p;
    }

    res.emplace_back(p, e);
  }

  if (N != 1)
  {
    res.emplace_back(N, 1);
  }
  return res;
}

Vl divisor(ll n)
{
  Vl ret;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Vl a(n), b(n), c(n);
  Pl ma, mb, mc;
  ma.first = mb.first = mc.first = LINF;     // min
  ma.second = mb.second = mc.second = -LINF; // max

  REP(i, n)
  {
    cin >> a[i] >> b[i] >> c[i];
    chmin(ma.first, a[i]);
    chmin(mb.first, b[i]);
    chmin(mc.first, c[i]);
    chmax(ma.second, a[i]);
    chmax(mb.second, b[i]);
    chmax(mc.second, c[i]);
  }

  Vl a0(n), a1(n), b0(n), b1(n), c0(n), c1(n);
  REP(i, n)
  {
    a0[i] = a[i] - ma.first;
    a1[i] = -(a[i] - ma.second);

    b0[i] = b[i] - mb.first;
    b1[i] = -(b[i] - mb.second);

    c0[i] = c[i] - mc.first;
    c1[i] = -(c[i] - mc.second);
  }

  VVl dp000(n, Vl(m)), dp001(n, Vl(m)), dp010(n, Vl(m)), dp011(n, Vl(m)), dp100(n, Vl(m)), dp101(n, Vl(m)), dp110(n, Vl(m)), dp111(n, Vl(m));
  Vl ans;

  dp000[0][0] = a0[0] + b0[0] + c0[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp000[i][0] = max(dp000[i - 1][0], a0[i] + b0[i] + c0[i]);
        continue;
      }
      if (i >= j)
      {
        dp000[i][j] = max(dp000[i - 1][j], dp000[i - 1][j - 1] + a0[i] + b0[i] + c0[i]);
      }
    }
  }

  ans.push_back(dp000[n - 1][m - 1] + m * (ma.first + mb.first + mc.first));

  dp001[0][0] = a0[0] + b0[0] + c1[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp001[i][0] = max(dp001[i - 1][0], a0[i] + b0[i] + c1[i]);
        continue;
      }
      if (i >= j)
      {
        dp001[i][j] = max(dp001[i - 1][j], dp001[i - 1][j - 1] + a0[i] + b0[i] + c1[i]);
      }
    }
  }

  ans.push_back(dp001[n - 1][m - 1] + m * (ma.first + mb.first + mc.second));

  dp010[0][0] = a0[0] + b1[0] + c0[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp010[i][0] = max(dp010[i - 1][0], a0[i] + b1[i] + c0[i]);
        continue;
      }
      if (i >= j)
      {
        dp010[i][j] = max(dp010[i - 1][j], dp010[i - 1][j - 1] + a0[i] + b1[i] + c0[i]);
      }
    }
  }

  ans.push_back(dp010[n - 1][m - 1] + m * (ma.first + mb.second + mc.first));

  dp011[0][0] = a0[0] + b1[0] + c1[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp011[i][0] = max(dp011[i - 1][0], a0[i] + b1[i] + c1[i]);
        continue;
      }
      if (i >= j)
      {
        dp011[i][j] = max(dp011[i - 1][j], dp011[i - 1][j - 1] + a0[i] + b1[i] + c1[i]);
      }
    }
  }

  ans.push_back(dp011[n - 1][m - 1] + m * (ma.first + mb.second + mc.second));

  dp100[0][0] = a1[0] + b0[0] + c0[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp100[i][0] = max(dp100[i - 1][0], a1[i] + b0[i] + c0[i]);
        continue;
      }
      if (i >= j)
      {
        dp100[i][j] = max(dp100[i - 1][j], dp100[i - 1][j - 1] + a1[i] + b0[i] + c0[i]);
      }
    }
  }

  ans.push_back(dp100[n - 1][m - 1] + m * (ma.second + mb.first + mc.first));

  dp101[0][0] = a1[0] + b0[0] + c1[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp101[i][0] = max(dp101[i - 1][0], a1[i] + b0[i] + c1[i]);
        continue;
      }
      if (i >= j)
      {
        dp101[i][j] = max(dp101[i - 1][j], dp101[i - 1][j - 1] + a1[i] + b0[i] + c1[i]);
      }
    }
  }

  ans.push_back(dp101[n - 1][m - 1] + m * (ma.second + mb.first + mc.second));

  dp110[0][0] = a1[0] + b1[0] + c0[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp110[i][0] = max(dp110[i - 1][0], a1[i] + b1[i] + c0[i]);
        continue;
      }
      if (i >= j)
      {
        dp110[i][j] = max(dp110[i - 1][j], dp110[i - 1][j - 1] + a1[i] + b1[i] + c0[i]);
      }
    }
  }

  ans.push_back(dp110[n - 1][m - 1] + m * (ma.second + mb.second + mc.first));

  dp111[0][0] = a1[0] + b1[0] + c1[0];
  REP2(i, 1, n)
  {
    REP(j, m)
    {
      if (j == 0)
      {
        dp111[i][0] = max(dp110[i - 1][0], a1[i] + b1[i] + c1[i]);
        continue;
      }
      if (i >= j)
      {
        dp111[i][j] = max(dp111[i - 1][j], dp111[i - 1][j - 1] + a1[i] + b1[i] + c1[i]);
      }
    }
  }

  ans.push_back(dp111[n - 1][m - 1] + m * (ma.second + mb.second + mc.second));

  sort(ans.begin(), ans.end());

  cout << ans.back() << endl;

  return 0;
}