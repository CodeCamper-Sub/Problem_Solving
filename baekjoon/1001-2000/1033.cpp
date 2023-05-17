#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, a, b, p, q;
vector<vector<tuple<ll, ll, ll>>> e;
vector<pair<ll, ll>> visited;

void dfs(ll now) {
  for(auto [next, p, q]: e[now]) {
    if(visited[next].first == 0 && visited[next].second == 0) {
      ll np = visited[now].first * p;
      ll nq = visited[now].second * q;
      ll g = gcd(np, nq);
      visited[next] = {np / g, nq / g};
      dfs(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n);
  visited.assign(n, {0, 0});
  for(ll i = 0; i < n - 1; i++) {
    cin >> a >> b >> p >> q;
    ll g = gcd(p, q);
    e[a].push_back({b, p / g, q / g});
    e[b].push_back({a, q / g, p / g});
  }

  visited[0] = {1, 1};
  dfs(0);
  
  ll g = 1;
  for(ll i = 0; i < n; i++) {
    g = lcm(g, visited[i].first);
  }
  for(ll i = 0; i < n; i++) {
    cout << g / visited[i].first * visited[i].second << ' ';
  }
  
  return 0;
}