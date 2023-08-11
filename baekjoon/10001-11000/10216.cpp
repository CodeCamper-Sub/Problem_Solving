#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<tuple<ll, ll, ll>> v;
vector<vector<ll>> e;
vector<ll> visited;

void init() {
  cin >> n;
  v.assign(n, tuple<ll, ll, ll>());
  e.assign(n, vector<ll>());
  for(auto& [y, x, r]: v) cin >> y >> x >> r;
}

void dfs(ll now) {
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      dfs(next);
    }
  }
}

void solve() {
  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      auto [y, x, r] = v[i];
      auto [ny, nx, nr] = v[j];
      if((y - ny) * (y - ny) + (x - nx) * (x - nx) <= (r + nr) * (r + nr)) {
        e[i].push_back(j);
        e[j].push_back(i);
      }
    }
  }

  visited.assign(n, false);
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    if(!visited[i]) {
      visited[i] = true;
      dfs(i);
      answer++;
    }
  }

  cout << answer << '\n';
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