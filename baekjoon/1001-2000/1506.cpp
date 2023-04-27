#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, visited_cnt, scc_cnt;
vector<ll> c, visited, scc, path;
vector<vector<ll>> e, scc_cost;

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
      scc_cost[scc_cnt].push_back(c[node]);
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
  
  cin >> n;
  c.resize(n);
  e.resize(n);
  scc_cost.resize(n);
  for(ll& c: c) cin >> c;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      char k;
      cin >> k;
      if(k == '1') {
        e[i].push_back(j);
      }
    }
  }

  visited.assign(n, -1);
  scc.assign(n, -1);
  
  for(ll i = 0; i < n; i++){
    if(visited[i] == -1) dfs(i);
  }

  ll answer = 0;
  for(ll i = 0; i < scc_cnt; i++) {
    answer += *min_element(scc_cost[i].begin(), scc_cost[i].end());
  }

  cout << answer << '\n';
  
  return 0;
}