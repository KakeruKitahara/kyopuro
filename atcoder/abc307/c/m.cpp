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
  int ha, wa;
  cin >> ha >> wa;
  VS a(ha);
  REP(i, ha)
  {
    cin >> a[i];
  }

  int hb, wb;
  cin >> hb >> wb;
  VS b(hb);
  REP(i, hb)
  {
    cin >> b[i];
  }

  int hx, wx;
  cin >> hx >> wx;
  VS x(hx);
  REP(i, hx)
  {
    cin >> x[i];
  }

  VS c1(80);
  REP(i, 80)
  {
    REP(j, 80)
    {
      c1[i].push_back('.');
    }
  }

  VS c2 = c1;

  REP(i, ha)
  {
    REP(j, wa)
    {
      c1[i + 35][j + 35] = a[i][j];
    }
  }

  REP(i, 80 - hb)
  {
    REP(j, 80 - wb)
    {
      VS t = c1;
      int cnt = 0;
      REP(i2, hb)
      {
        REP(j2, wb)
        {
          if (b[i2][j2] == '#')
          {
            t[i + i2][j + j2] = b[i2][j2];
          }
        }
      }

      REP(i2, 80)
      {
        REP(j2, 80)
        {
          if (t[i2][j2] == '#')
          {
            cnt++;
          }
        }
      }

      REP(i2, 80 - hx)
      {
        REP(j2, 80 - wx)
        {
          int cnt2 = 0;
          int f = 0;
          REP(i3, hx)
          {
            REP(j3, wx)
            {
              if (t[i2 + i3][j2 + j3] == x[i3][j3])
              {
                if (t[i2 + i3][j2 + j3] == '#')
                {
                  cnt2++;
                }
              }
              else
              {
                f = 1;
                break;
              }
            }
            if (f == 1)
            {
              break;
            }
          }
          if (cnt2 == cnt && f == 0)
          {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  REP(i, hb)
  {
    REP(j, wb)
    {
      c2[i + 15][j + 15] = b[i][j];
    }
  }

  REP(i, 80 - ha)
  {
    REP(j, 80 - wa)
    {
      VS t = c2;
      int cnt = 0;
      REP(i2, ha)
      {
        REP(j2, wa)
        {
          if (a[i2][j2] == '#')
          {
            t[i + i2][j + j2] = a[i2][j2];
          }
        }
      }

      REP(i2, 80)
      {
        REP(j2, 80)
        {
          if (t[i2][j2] == '#')
          {
            cnt++;
          }
        }
      }

      REP(i2, 80 - hx)
      {
        REP(j2, 80 - wx)
        {
          int cnt2 = 0;
          int f = 0;
          REP(i3, hx)
          {
            REP(j3, wx)
            {
              if (t[i2 + i3][j2 + j3] == x[i3][j3])
              {
                if (t[i2 + i3][j2 + j3] == '#')
                {
                  cnt2++;
                }
              }
              else
              {
                f = 1;
                break;
              }
            }
            if (f == 1)
            {
              break;
            }
          }
          if (cnt2 == cnt && f == 0)
          {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}