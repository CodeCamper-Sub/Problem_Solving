#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<pair<pair<char, ll>, pair<char, ll>>> v;
vector<vector<ll>> dp;

void init() {
  cin >> n;
  v.resize(n);
  dp.assign(7, vector<ll>(n, false));
  for(ll i = 0; i < n; i++) {
    cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
  }
}

void solve() {
  vector<ll> now(7, false);
  now[1] = true;
  for(auto [first, second]: v) {
    auto [f_command, f_num] = first;
    auto [s_command, s_num] = second;
    vector<ll> next(7, false);
    for(ll i = 0; i < 7; i++) {
      if(!now[i]) continue;
      if(f_command == '+') {
        ll nxt = i + f_num;
        nxt %= 7;
        next[nxt] = true;
      } else {
        ll nxt = i * f_num;
        nxt %= 7;
        next[nxt] = true;
      }

      if(s_command == '+') {
        ll nxt = i + s_num;
        nxt %= 7;
        next[nxt] = true;
      } else {
        ll nxt = i * s_num;
        nxt %= 7;
        next[nxt] = true;
      }
    }
    now = next;
  }

  if(now[0]) {
    cout << "LUCKY\n";
  } else {
    cout << "UNLUCKY\n";
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