#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, a, b, visited[20200], scc[20200], visited_cnt, scc_cnt;
vector<ll> e[20200], scc_elements[20200];
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
      scc_elements[scc_cnt].push_back(node);
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
    e[-a+N].push_back(b+N);
    e[-b+N].push_back(a+N);
  }
  memset(visited, -1, (2*N+1)*sizeof(ll));
  memset(scc, -1, (2*N+1)*sizeof(ll));
  for(ll i = 0; i <= 2*N; i++) {
    if(visited[i] == -1) {
      dfs(i);
    }
  }

  bool is_possible = true;
  for(ll i = 0; i < scc_cnt; i++) {
    sort(scc_elements[i].begin(), scc_elements[i].end());
    for(auto iter = scc_elements[i].begin(); iter != scc_elements[i].end() && *iter < N; iter++) {
      auto positive_iter = lower_bound(scc_elements[i].begin(), scc_elements[i].end(), 2 * N - (*iter));
      if(*positive_iter == 2 * N - (*iter)) {
        is_possible = false;
        break;
      }
    }
    if(!is_possible) break;
  }

  if(is_possible) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }

  return 0;
}