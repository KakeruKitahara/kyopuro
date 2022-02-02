#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main(){
  return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP2(i, a, n) for (int i = a; i < n; i++)
#define REPR(i, n) for (int i = n - 1; 0 <= n; i--)
#define REPR2(i, a, n) for (int i = a; 0 <= n; i--)
using V = vector<int>;
using P = pair<int, int>;
using ll = long long;
using namespace std;

int main()
{
  int cnt = 0;
  string x;
  ll m, right = 1E+6 + 1;
  int tmp = -1;
  cin >> x >> m;

  REP(i, x.size())
  {
    int tx = x[i] - '0';
    tmp = max(tmp, tx);
  }

  ll sum, center, left = tmp;

  REP(i, 1E+6)
  {
    ll tms = m;
    string tmss;
    sum = 0;
    center = (left + right) / 2;
    cout << center << "\n";
    while (0 < tms)
    {
      sum += tms % center;
      tms /= center;
    }
    tmss = to_string(sum);

    if (tmss.size() > x.size())
    {
      right = center;
      cout << "a";
    }
    else if (tmss.size() < x.size())
    {
      left = center;
      cout << "b";
    }
    else
    {
      int aa = 0;
      REP(j, x.size())
      {
        if (x[j] < tmss[j])
        {
          left = center;
        }
        else if (x[j] > tmss[j])
        {
          right = center;
        }
        else
        {
          aa++;
        }
      }
      if (x.size() == aa)
        break;
    }
  }

  cout << center - tmp;
  return 0;
}
*/