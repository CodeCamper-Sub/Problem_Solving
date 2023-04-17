#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll T;
ll N, M, x, y;

ll dfs(ll now, vector<ll> e[], vector<ll> &path, ll visited[], ll scc[], ll& visited_cnt, ll& scc_cnt) {
  visited[now] = visited_cnt++;
  path.push_back(now);
  ll result = visited[now];
  for(ll i = 0; i < e[now].size(); i++) {
    ll next = e[now][i];
    if(visited[next] == -1) {
      result = min(result, dfs(next, e, path, visited, scc, visited_cnt, scc_cnt));
    } else if(scc[next] == -1) {
      result = min(result, visited[next]);
    }
  }
  if(result == visited[now]) {
    while(!path.empty()) {
      ll node = path.back();
      path.pop_back();
      scc[node] = scc_cnt;
      if(node == now) break;
    }
    scc_cnt++;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> T;
  while(T--) {
    cin >> N >> M;
    vector<ll>* e = new vector<ll>[N+1];
    ll* visited = new ll[N+1];
    ll* scc = new ll[N+1];

    for(ll i = 0; i < M; i++) {
      cin >> x >> y;
      e[x].push_back(y);
    }
    for(ll i = 1; i <= N; i++) {
      visited[i] = -1;
      scc[i] = -1;
    }
    ll scc_cnt = 0;
    ll visited_cnt = 0;
    vector<ll> path;
    for(ll i = 1; i <= N; i++) {
      if(visited[i] == -1) {
        dfs(i, e, path, visited, scc, visited_cnt, scc_cnt);
      }
    }

    set<ll>* scc_edges = new set<ll>[scc_cnt];
    ll* ind = new ll[scc_cnt];
    for(ll now = 1; now <= N; now++) {
      for(ll i = 0; i < e[now].size(); i++) {
        ll next = e[now][i];
        if(scc[now] != scc[next]) {
          scc_edges[scc[now]].insert(scc[next]);
        }
      }
    }
    for(ll i = 0; i < scc_cnt; i++) {
      ind[i] = 0;
    }
    for(ll now = 0; now < scc_cnt; now++) {
      for(ll next: scc_edges[now]) {
        ind[next]++;
      }
    }
    ll answer = 0;
    for(ll i = 0; i < scc_cnt; i++) {
      if(ind[i] == 0) answer++;
    }
    cout << answer << '\n';

    delete[](ind);
    delete[](scc_edges);
    delete[](scc);
    delete[](visited);
    delete[](e);
  }

  return 0;
}