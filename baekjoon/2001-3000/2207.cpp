#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, x, y, visited_cnt, scc_cnt;
vector<ll> visited, scc, path;
vector<vector<ll>> e;

ll dfs(ll now) {
  visited[now] = visited_cnt++;
  path.push_back(now);
  ll result = visited[now];
  for(ll next: e[now]) {
    if(visited[next] == -1) {
      result = min(result, dfs(next));
    } else if(scc[next] == -1) {
      result = min(result, visited[next]);
    }
  }
  if(result == visited[now]) {
    while(path.size()) {
      ll node = path.back();
      path.pop_back();
      scc[node] = scc_cnt;
      if(now == node) break;
    }
    scc_cnt++;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(2 * m + 1);
  visited.assign(2 * m + 1, -1);
  scc.assign(2 * m + 1, -1);
  for(ll i = 0; i < n; i++) {
    cin >> x >> y;
    e[m - x].push_back(m + y);
    e[m - y].push_back(m + x);
  }

  for(ll i = 0; i <= 2 * m; i++) {
    if(visited[i] == -1) dfs(i);
  }

  for(ll i = 1; i <= m; i++) {
    if(scc[m + i] == scc[m - i]) {
      cout << "OTL\n";
      return 0;
    }
  }

  cout << "^_^\n";
  
  return 0;
}