#include <bits/stdc++.h>
#define INF 999999999999
using namespace std;

int m, n, v, w, visited[1001000], visited_cnt, scc[1001000], scc_cnt;
int node_cnt[1001000], scc_memo[1001000];
vector<int> e[1001000], scc_e[1001000];
stack<int> path;

int dfs(int now) {
  visited[now] = visited_cnt++;
  path.push(now);
  int result = visited[now];
  for(int next: e[now]){ 
    if(visited[next] == -1) {
      result = min(result, dfs(next));
    } else if(scc[next] == -1) {
      result = min(result, visited[next]);
    }
  }

  if(result == visited[now]) {
    while(!path.empty()) {
      int node = path.top();
      path.pop();
      scc[node] = scc_cnt;
      if(now == node) break;
    }
    scc_cnt++;
  }
  return result;
}

int scc_dfs(int now) {
  if(scc_memo[now] != -1) {
    return scc_memo[now];
  }
  int result = 0;
  for(int next: scc_e[now]) {
    result = max(result, scc_dfs(next));
  }
  return scc_memo[now] = result + node_cnt[now];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;

  for(int i = 0; i < m; i++) {
    cin >> v >> w;
    e[v].push_back(w);
  }

  for(int i = 0; i < n; i++) {
    visited[i] = -1;
    scc[i] = -1;
  }
  for(int i = 0; i < n; i++) {
    if(visited[i] == -1) {
      dfs(i);
    }
  }

  for(int i = 0; i < n; i++) {
    node_cnt[scc[i]]++;
    scc_memo[i] = -1;
    for(int next: e[i]) {
      if(scc[i] != scc[next]) {
        scc_e[scc[i]].push_back(scc[next]);
      }
    }
  }

  int answer = -1;
  for(int i = 0; i < scc_cnt; i++) {
    if(scc_memo[i] == -1) {
      answer = max(answer, scc_dfs(i));
    }
  }
  if(answer != -1) {
    cout << answer << '\n';
  } else {
    cout << 0 << '\n';
  }

  return 0;
}