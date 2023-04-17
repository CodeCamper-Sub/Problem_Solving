#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, a, b, visited[20200], scc[20200], visited_cnt, scc_cnt;
vector<ll> e[20200], scc_nodes[20200];
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
      scc_nodes[scc_cnt].push_back(node);
      if(now == node) break;
    }
    scc_cnt++;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for(ll i = 0; i < M; i++) {
    cin >> a >> b;
    e[-a + N].push_back(b + N);
    e[-b + N].push_back(a + N);
  }

  fill(visited, visited + 20200, -1);
  fill(scc, scc + 20200, -1);

  for(ll i = 0; i <= 2 * N; i++) {
    if(visited[i] == -1) {
      dfs(i);
    }
  }

  bool is_possible = true;
  for(ll i = 0; i < scc_cnt; i++) {
    sort(scc_nodes[i].begin(), scc_nodes[i].end());
    for(ll j = 0; j < scc_nodes[i].size() && scc_nodes[i][j] < N; j++) {
      auto iter = lower_bound(scc_nodes[i].begin(), scc_nodes[i].end(), 2 * N - scc_nodes[i][j]);
      if(iter != scc_nodes[i].end() && *iter == 2 * N - scc_nodes[i][j]) {
        is_possible = false;
        break;
      }
    }
    if(!is_possible) break;
  }

  if(!is_possible) {
    cout << "0\n";
    return 0;
  } else {
    cout << "1\n";
  }

  ll state[20200];
  fill(state, state + 20200, -1);
  for(ll i = scc_cnt - 1; i >= 0; i--) {
    for(ll node: scc_nodes[i]) {
      if(state[node] == -1) {
        state[node] = 0;
        ll matched_node = 2 * N - node;
        state[matched_node] = 1;
      }
    }
  }

  for(ll i = N + 1; i <= 2 * N; i++) {
    cout << state[i] << ' ';
  }

  return 0;
}