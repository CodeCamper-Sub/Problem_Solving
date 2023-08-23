#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9+7)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, k;
vector<ll> color;
vector<vector<ll>> e;
vector<vector<ll>> memo;

ll tree_dp(ll now, ll parent, ll c) {
  if(memo[c][now] != -1) return memo[c][now];
  if(color[now] != -1 && color[now] != c) return memo[c][now] = 0;
  memo[c][now] = 1;
  for(ll next: e[now]) {
    if(next == parent) continue;
    ll p = 0;
    for(ll nc = 0; nc < 3; nc++) {
      if(c == nc) continue;
      p += tree_dp(next, now, nc);
      p %= MOD;
    }
    memo[c][now] *= p;
    memo[c][now] %= MOD;
  }
  return memo[c][now];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  color.assign(n, -1);
  memo.assign(3, vector<ll>(n, -1));
  e.resize(n);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  for(ll i = 0; i < k; i++) {
    ll v, c;
    cin >> v >> c;
    color[--v] = --c;
  }

  ll answer = 0;
  for(ll c = 0; c < 3; c++) {
    answer += tree_dp(0, -1, c);
    answer %= MOD;
  }
  cout << answer << '\n';

 
  return 0;
}