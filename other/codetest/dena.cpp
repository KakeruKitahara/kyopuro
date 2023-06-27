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
using Pl = pair<long long, long long>;
using VP = vector<pair<int, int>>;
using VVP = vector<vector<pair<int, int>>>;
using S = string;
using VS = vector<string>;
using VVS = vector<vector<string>>;
using ll = long long;
constexpr int IINF = 1000000000 + 8;
constexpr long long LINF = 1000000000000000000LL + 8;

void f1()
{
  int m;
  cin >> m;
  map<int, int> store;

  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    store[a] = b;
  }

  cin.ignore();
  S line;
  while (!cin.eof())
  {
    getline(cin, line);
    if (line.empty())
    {
      break;
    }
    stringstream ss(line);
    S a;
    int b, c, d;
    ss >> a >> b >> c >> d;

    if (store[c] < d)
    {
      cout << "sold out " << b << endl;
    }
    else
    {
      REP(j, d)
      {
        cout << "received order " << b << " " << c << endl;
        store[c]--;
      }
    }
  }
}

void f2()
{

  int m, k;
  cin >> m >> k;

  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
  }

  cin.ignore();
  S line;

  multiset<int> cook;
  queue<int> wait;
  while (!cin.eof())
  {
    getline(cin, line);
    if (line.empty())
    {
      break;
    }
    stringstream ss(line);
    S a, a2;
    int b, c;
    ss >> a;
    if (a == "received")
    {
      ss >> a2 >> b >> c;
      if (cook.size() < k)
      {
        cout << c << endl;
        cook.insert(c);
      }
      else
      {
        wait.push(c);
      }
      if (wait.size() >= 1)
      {
        cout << "wait" << endl;
      }
    }
    else
    {
      ss >> b;
      if (!cook.count(b))
      {
        cout << "unexpected input" << endl;
      }
      else
      {
        cout << "ok";
        cook.erase(cook.find(b));
        if (wait.size() != 0)
        {
          int p = wait.front();
          wait.pop();
          cout << " " << p << endl;
          cook.insert(p);
        }
        else
        {
          cout << endl;
        }
      }
    }
  }
}

void f3()
{
  int m;
  cin >> m;

  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
  }

  cin.ignore();
  S line;

  map<int, queue<int>> recive;

  while (!cin.eof())
  {
    getline(cin, line);
    if (line.empty())
    {
      break;
    }
    stringstream ss(line);
    S a, a2;
    int b, c;
    ss >> a;
    if (a == "received")
    {
      ss >> a2 >> b >> c;
      recive[c].push(b);
    }
    else
    {
      ss >> b;
      if (recive[b].size() > 0)
      {
        int num = recive[b].front();
        recive[b].pop();
        cout << "ready"
             << " " << num << " " << b << endl;
      }
    }
  }
}

void f4()
{
  int m;
  cin >> m;
  map<int, int> item;

  REP(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    item[a] = c;
  }

  cin.ignore();
  S line;

  map<int, multiset<int>> wait;
  map<int, int> sum;

  while (!cin.eof())
  {
    getline(cin, line);
    if (line.empty())
    {
      break;
    }
    stringstream ss(line);
    S a, a2;
    int b, c;
    ss >> a;
    if (a == "received")
    {
      ss >> a2 >> b >> c;
      wait[b].insert(c);
    }
    else if (a == "ready")
    {
      ss >> b >> c;
      wait[b].erase(wait[b].find(c));
      if (!sum.count(b))
      {
        sum[b] = item[c];
      }
      else
      {
        sum[b] += item[c];
      }
    }
    else
    {
      ss >> b;
      if (wait[b].size() == 0)
      {
        cout << sum[b] << endl;
        sum.erase(b);
      }
      else
      {
        cout << "please wait"  << endl;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  if (n == 1)
  {
    f1();
  }
  else if (n == 2)
  {
    f2();
  }
  else if (n == 3)
  {
    f3();
  }
  else
  {
    f4();
  }
  return 0;
}