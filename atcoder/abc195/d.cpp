#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= i; i--)
#define REPR2(i, n, a) for (int i = n; a <= i; i--)
using V = vector<int>;
using P = pair<int, int>;
using S = string;
using ll = long long;
using namespace std;

int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<P> v(n);
  int w[n];

  REP(i, n)
  {
    v[i].second = i;
    cin >> w[i] >> v[i].first;
  }

  vector<P> x(m);
  REP(i, m)
  {
    cin >> x[i].first;
    x[i].second = i;
  }

  int ch[m];

  P lr[q];
  REP(i, q)
  {
    cin >> lr[i].first >> lr[i].second;
  }

  sort(v.rbegin(), v.rend());
  sort(x.begin(), x.end());

  int sum;
  REP(i, q)
  {
    REP(o, m)
    {
      if (lr[i].first - 1 <= x[o].second && lr[i].second - 1 >= x[o].second)
      {
        ch[x[o].second] = 1;
      }
      else{
        ch[x[o].second] = 0;
      }

    }
    sum = 0;
    REP(j, n)
    {
      REP(k, m)
      {
        if (w[v[j].second] <= x[k].first && ch[x[k].second] == 0)
        {
          sum += v[j].first;
          ch[x[k].second] = 1;
          break;
        }
      }
    }
    cout << sum << "\n";
  }

  return 0;
}

/*
3 4 4
1 9
5 3
7 8
1 8 6 9
4 4
1 4
1 3
1 1
*/