#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, v, w, visited_cnt, scc_cnt;
vector<ll> e[200200], path;
set<ll> scc_e[200200];
ll visited[200200], scc[200200], ind[200200];

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
    while(!path.empty()) {
      ll node = path.back();
      path.pop_back();
      scc[node] = scc_cnt;
      if(now == node) break;
    }
    scc_cnt++;
  }
  return result;
}

bool scc_dfs(ll now) {
  if(now == 0) return true;
  if(scc_e[now].find(now-1) != scc_e[now].end()) {
    return scc_dfs(now-1);
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for(ll i = 0; i < M; i++){
    cin >> v >> w;
    e[v].push_back(w);
  }
  for(ll i = 0; i <= N; i++) {
    visited[i] = -1;
    scc[i] = -1;
  }
  for(ll i = 1; i <= N; i++) {
    if(visited[i] == -1) {
      dfs(i);
    }
  }

  for(ll now = 1; now <= N; now++) {
    for(ll next: e[now]) {
      if(scc[now] != scc[next]) {
        scc_e[scc[now]].insert(scc[next]);
      }
    }
  }

  for(ll now = 0; now < scc_cnt; now++) {
    for(ll next: scc_e[now]) {
      ind[next]++;
    }
  }

  ll start_scc = -1;
  bool is_possible = true;
  for(ll i = 0; i < scc_cnt; i++) {
    if(ind[i] == 0) {
      if(start_scc == -1) {
        start_scc = i;
      } else {
        is_possible = false;
      }
    }
  }
  
  if(is_possible) {
    is_possible = scc_dfs(scc_cnt-1);
  } 

  if(is_possible) {
    set<ll> answer;
    for(ll i = 1; i <= N; i++) {
      if(scc[i] == start_scc) {
        answer.insert(i);
      }
    }
    cout << answer.size() << '\n';
    for(ll node: answer) {
      cout << node << ' ';
    }
  } else {
    cout << '0';
  }

  return 0;
}