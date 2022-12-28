#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, a, b, visited[2020], visited_cnt, scc[2020], scc_cnt;
vector<ll> e[2020];
stack<ll> path;

ll dfs(ll now) {
  visited[now] = visited_cnt++;
  path.push(now);
  ll result = visited[now];
  for(ll next: e[now]) {
    if(visited[next] == -1) {
      result = min(result, dfs(next));
    } else if (scc[next] == -1) {
      result = min(result, visited[next]);
    }
  }
  if(result == visited[now]) {
    while(!path.empty()) {
      ll node = path.top(); path.pop();
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
  
  while(cin >> n >> m) {
    for(ll i = 0; i < m; i++) {
      cin >> a >> b;
    
      e[-a + n].push_back(b + n);
      e[-b + n].push_back(a + n);
    }
    e[-1 + n].push_back(1 + n);

    fill(visited, visited + 2020, -1);
    visited_cnt = 0;
    fill(scc, scc + 2020, -1);
    scc_cnt = 0;
    for(ll i = 0; i <= 2 * n; i++) {
      if(visited[i] == -1) {
        dfs(i);
      }
    }

    bool is_possible = true;
    for(ll i = 0; i < n; i++) {
      if(scc[i] == scc[2 * n - i]) {
        is_possible = false;
        break;
      }
    }
    if(is_possible) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }

    while(!path.empty()) path.pop();
    for(ll i = 0; i <= 2 * n + 1; i++) e[i].clear();
  }

  return 0;
}