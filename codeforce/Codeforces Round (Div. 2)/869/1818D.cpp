#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
bool fish_found;
vector<ll> visited, cycle, included_in_cycle;
vector<vector<ll>> e;

void init() {
  cin >> n >> m;
  e.assign(n + 1, vector<ll>());
  fish_found = false;
  for(ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  cycle.clear();
}

void dfs(ll now, vector<ll>& path) {
  for(ll next: e[now]) {
    if(visited[next] && path.size() >= 2 && path[path.size() - 2] != next) {
      ll k = -1;
      for(ll i = 0; i < path.size(); i++) {
        if(path[i] == next) k = i;
        if(k <= i && e[path[i]].size() >= 4) {
          fish_found = true;
          break;
        }
      }
      if(fish_found) {
        for(ll i = k; i < path.size(); i++) {
          cycle.push_back(path[i]);
        }
      }
    }
    if(fish_found) break;
  }

  if(fish_found) return;

  for(ll next: e[now]) {
    if(!visited[next]) {
      path.push_back(next);
      visited[next] = true;
      dfs(next, path);
      if(fish_found) {
        return;
      } else {
        path.pop_back();
      }
    }
  }
}

void solve() {
  if(n < 5 || m < 5) {
    cout << "NO\n";
    return;
  }
  visited.assign(n + 1, false);
  vector<ll> path;
  for(ll i = 1; i <= n; i++) {
    if(!visited[i]) {
      path.push_back(i);
      visited[i] = true;
      dfs(i, path);
      if(fish_found) {
        break;
      } else {
        path.pop_back();
      }
    }
  }
  if(!fish_found) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    included_in_cycle.assign(n + 1, false);
    for(ll now: cycle) included_in_cycle[now] = true;
    vector<pair<ll, ll>> answer_edges;
    for(ll i = 0; i < cycle.size(); i++) {
      ll now = cycle[i];
      if(e[now].size() < 4) continue;
      vector<ll> adj, not_adj, not_included;
      for(ll j = 0; j < e[now].size(); j++) {
        ll next = e[now][j];
        if (!included_in_cycle[next]) {
          not_included.push_back(next);
        } else if(cycle[(i + 1) % cycle.size()] == next || cycle[(i - 1 + cycle.size()) % cycle.size()] == next) {
          adj.push_back(next);
        } else {
          not_adj.push_back(next);
        }
      }
      if(not_included.size() >= 2) {
        for(ll j = 0; j < cycle.size(); j++) {
          answer_edges.push_back({cycle[j], cycle[(j + 1) % cycle.size()]});
        }
        answer_edges.push_back({now, not_included[0]});
        answer_edges.push_back({now, not_included[1]});
      } else if(not_included.size() == 1) {
        answer_edges.push_back({now, not_included[0]});
        for(ll j = 0; j < cycle.size(); j++) {
          answer_edges.push_back({cycle[(i + j) % cycle.size()], cycle[(i + j + 1) % cycle.size()]});
          if(cycle[(i + j + 1) % cycle.size()] == not_adj[0]) {
            answer_edges.push_back({not_adj[0], now});
            break;
          }
        }
      } else {
        ll k = -1;
        for(ll j = 0; j < cycle.size(); j++) {
          if(cycle[(i + j) % cycle.size()] == not_adj[0] || cycle[(i + j) % cycle.size()] == not_adj[1]) {
            if(k == -1) {
              k = j;
              answer_edges.push_back({now, cycle[(i + j) % cycle.size()]});
            } else {
              answer_edges.push_back({cycle[(i + j - 1 + cycle.size()) % cycle.size()], cycle[(i + j) % cycle.size()]});
              answer_edges.push_back({cycle[(i + j) % cycle.size()], now});
              break;
            }
          } else {
            if(k == -1) {
              continue;
            } else {
              answer_edges.push_back({cycle[(i + j - 1 + cycle.size()) % cycle.size()], cycle[(i + j) % cycle.size()]});
            }
          }
        }
      }
      break;
    }
    cout << answer_edges.size() << '\n';
    for(auto [u, v]: answer_edges) {
      cout << u << ' ' << v << '\n';
    }
  }
  return;
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