#include <bits/stdc++.h>
#include <chrono>
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

map<S, Pl> mappos;
map<S, bool> mapholday;
map<S, set<int>> mapholdw;
map<S, P> maprest;
map<S, int> mapmin;
map<S, int> mapfree;
VV holidays;

VS split(S str, S separator)
{
  if (separator == "")
    return {str};
  VS result;
  string tstr = str + separator;
  long l = tstr.length(), sl = separator.length();
  string::size_type pos = 0, prev = 0;

  for (; pos < l && (pos = tstr.find(separator, pos)) != string::npos; prev = (pos += sl))
  {
    result.emplace_back(tstr, prev, pos - prev);
  }
  return result;
}

int s2i(S s)
{
  int i;
  istringstream(s) >> i;
  return i;
}

V String2ymd(S str)
{
  VS split_str = split(str, "-");
  V hmv;
  REP(i, split_str.size())
  {
    hmv.push_back(s2i(split_str[i]));
  }
  return hmv;
}

P String2hm(S str)
{
  VS split_str = split(str, ":");
  P hm;
  hm.first = s2i(split_str[0]);
  hm.second = s2i(split_str[1]);

  return hm;
}

int order(S stymd, V ymd, P md, S sname, int fee, Pl upos)
{
  Pl spos = mappos[sname];
  ll metric = (spos.first - upos.first) * (spos.first - upos.first) + (spos.second - upos.second) * (spos.second - upos.second);

  int cost = 0;

  if (metric < 10000)
  {
    cost = 300;
  }
  else if (metric < 1000000)
  {
    cost = 600;
  }
  else if (metric < 100000000)
  {
    cost = 900;
  }
  else
  {
    cost = 1200;
  }

  if (mapmin[sname] > fee)
  {
    return -1; // ERROE INSUFFICIENT
  }

  if (mapholday[sname] == true)
  {
    REP(i, holidays.size())
    {
      if (holidays[i][0] == ymd[1] && holidays[i][1] == ymd[2])
      {
        return -2; // ERROE CLOSED DAY
      }
    }
  }

  tm date = {};
  istringstream ss(stymd);
  ss >> get_time(&date, "%Y-%m-%d");
  chrono::system_clock::time_point tp = chrono::system_clock::from_time_t(mktime(&date));
  time_t tt = chrono::system_clock::to_time_t(tp);
  tm result_tm = *localtime(&tt);

  int wtoday = result_tm.tm_wday;
  if (mapholdw[sname].count(wtoday))
  {
    return -2;
  }

  if (mapfree.count(sname) && mapfree[sname] <= fee)
  {
    cost = 0;
  }

  return cost + fee;
}

void set_min(S sname, int fee)
{
  mapmin[sname] = fee;
}

void set_free(S sname, int fee)
{
  mapfree[sname] = fee;
}

void close_day(S sname, S wd)
{
  if (wd == "HOLIDAY")
  {
    mapholday[sname] = true;
  }
  else
  {
    if (wd == "SUN")
    {
      mapholdw[sname].insert(0);
    }
    else if (wd == "MOM")
    {
      mapholdw[sname].insert(1);
    }
    else if (wd == "TUR")
    {
      mapholdw[sname].insert(2);
    }
    else if (wd == "WED")
    {
      mapholdw[sname].insert(3);
    }
    else if (wd == "THU")
    {
      mapholdw[sname].insert(4);
    }
    else if (wd == "SAT")
    {
      mapholdw[sname].insert(5);
    }
    else
    {
      mapholdw[sname].insert(6);
    }
  }
}

void open_day(S sname, S wd)
{
  if (wd == "HOLIDAY")
  {
    mapholday[sname] = false;
  }
  else
  {
    if (wd == "SUN")
    {
      mapholdw[sname].erase(0);
    }
    else if (wd == "MOM")
    {
      mapholdw[sname].erase(1);
    }
    else if (wd == "TUR")
    {
      mapholdw[sname].erase(2);
    }
    else if (wd == "WED")
    {
      mapholdw[sname].erase(3);
    }
    else if (wd == "THU")
    {
      mapholdw[sname].erase(4);
    }
    else if (wd == "SAT")
    {
      mapholdw[sname].erase(5);
    }
    else
    {
      mapholdw[sname].erase(6);
    }
  }
}

void open_time(S name, P st, P ft){
  
}

void close_time(S name, P st, P ft){}


int main(int argc, char *argv[])
{
  S s;
  getline(cin, s);

  VS res = split(s, " ");
  int hnum = s2i(res[0]);
  int snum = s2i(res[1]);

  REP(i, hnum)
  {
    S s;
    getline(cin, s);
    V ym = String2ymd(s);
    holidays.push_back(ym);
  }

  REP(i, snum)
  {
    S s;
    getline(cin, s);
    VS res = split(s, " ");
    S sname = res[0];
    Pl p = {s2i(res[1]), s2i(res[2])};
    mappos[sname] = p;
  }
  while (!cin.eof())
  {
    S s;
    getline(cin, s);
    bool onlyNewlines = true;
    for (char c : s)
    {
      if (c != '\n')
      {
        onlyNewlines = false;
        break;
      }
    }

    if (onlyNewlines)
    {
      break;
    }

    VS res = split(s, " ");
    V ymd = String2ymd(res[0]);
    P hm = String2hm(res[1]);
    S od = res[2];
    S sname = res[3];

    if (od == "order")
    {
      int fee = s2i(res[4]);
      Pl upos = {s2i(res[5]), s2i(res[6])};
      int money = order(res[0], ymd, hm, sname, fee, upos);

      if (money == -1)
      {
        cout << res[0] << " " << res[1] << " ERROR INSUFFICIENT" << endl;
      }
      else if (money == -2)
      {
        cout << res[0] << " " << res[1] << " ERROR CLOSED DAY" << endl;
      }
      else if (money == -3)
      {
        cout << res[0] << " " << res[1] << " ERROR CLOSED TIME" << endl;
      }
      else
      {
        cout << res[0] << " " << res[1] << " " << money << endl;
      }
    }
    else if (od == "set_min")
    {
      int min_fee = s2i(res[4]);
      set_min(sname, min_fee);
    }
    else if (od == "set_free")
    {
      int free_fee = s2i(res[4]);
      set_free(sname, free_fee);
    }
    else if (od == "open_day")
    {
      S wd = res[4];
      open_day(sname, wd);
    }
    else if (od == "close_day")
    {
      S wd = res[4];
      close_day(sname, wd);
    }
    else if (od == "close_day")
    {
      S wd = res[4];
      close_day(sname, wd);
    }
    else if (od == "close_time")
    {
      P st = String2hm(res[4]);
      P ft = String2hm(res[5]);
      close_time(sname, st, ft);
    }
    else if (od == "open_time")
    {
      P st = String2hm(res[4]);
      P ft = String2hm(res[5]);
      open_time(sname, st, ft);
    }
  }
  return 0;
}
