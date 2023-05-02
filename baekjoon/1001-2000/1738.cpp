#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, u, v, w, has_cycle;
vector<ll> dist, cnt, inQ, visited, cycle_visited;
vector<vector<pair<ll, ll>>> e;
queue<ll> q;

bool dfs(ll now) {
  if(now == n) return true;
  ll result = false;
  for(auto [next, _]: e[now]) {
    if(!cycle_visited[next]) {
      cycle_visited[next] = true;
      result |= dfs(next);
      if(result) break;
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  
  for(ll i = 0; i < m; i++) {
    cin >> u >> v >> w;
    e[u].push_back({v, -w});
  }

  dist.assign(n + 1, INF);
  cnt.assign(n + 1, 0);
  inQ.assign(n + 1, false);
  visited.assign(n + 1, -1);

  inQ[1] = true;
  dist[1] = 0;
  q.push(1);
  while(q.size()) {
    ll now = q.front();
    inQ[now] = false;
    q.pop();
    if(cnt[now]++ == n) {
      cycle_visited.assign(n + 1, false);
      if(dfs(now)) {
        cout << -1 << '\n';
        return 0;
      }
    }
    for(auto [next, cost]: e[now]) {
      if(dist[next] > dist[now] + cost) {
        dist[next] = dist[now] + cost;
        visited[next] = now;
        if(!inQ[next] && cnt[next] <= n) {
          inQ[next] = true;
          q.push(next);
        }
      }
    }
  }

  if(dist[n] != INF) {
    stack<ll> path;
    ll now = n;
    while(now != -1) {
      path.push(now);
      now = visited[now];
    }
    while(path.size()) {
      cout << path.top() << ' ';
      path.pop();
    }
  } else {
    cout << -1 << '\n';
  }

  
  return 0;
}