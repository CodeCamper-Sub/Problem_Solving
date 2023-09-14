#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define min3(x, y, z) min(x, min(y, z))
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

string s;

void init() {
  cin >> s;
}

void solve() {
  vector<ll> o, q, w;
  for(ll i = 0; i < s.size(); i++) {
    char c = s[i];
    if(c == '(') {
      o.push_back(i);
    } else if(c == ')') {
      if(o.size()) o.pop_back();
      else if(q.size()) q.pop_back();
      else if(w.size()) continue;
      else {
        cout << "NO\n";
        return;
      }
    } else if(c == '?') {
      q.push_back(i);
    } else {
      w.push_back(i);
    }
  }
  reverse(o.begin(), o.end());
  reverse(q.begin(), q.end());
  reverse(w.begin(), w.end());
  string s;
  while(o.size() || q.size() || w.size()) {
    ll min_o = o.size() ? o.back() : INF;
    ll min_q = q.size() ? q.back() : INF;
    ll min_w = w.size() ? w.back() : INF;
    ll min_3 = min3(min_o, min_q, min_w);
    if(min_3 == min_o) {
      s.push_back(')');
      o.pop_back();
    } else if(min_3 == min_q) {
      s.push_back('?');
      q.pop_back();
    } else {
      s.push_back('*');
      w.pop_back();
    }
  }
  reverse(s.begin(), s.end());
  for(ll i = 0; i < s.size(); i++) {
    char c = s[i];
    if(c == '(') {
      o.push_back(i);
    } else if(c == ')') {
      if(o.size()) o.pop_back();
      else if(q.size()) q.pop_back();
      else if(w.size()) continue;
      else {
        cout << "NO\n";
        return;
      }
    } else if(c == '?') {
      q.push_back(i);
    } else {
      w.push_back(i);
    }
  }
  if(q.size()) {
    if(w.size() || ll(q.size()) % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}