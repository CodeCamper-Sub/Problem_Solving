#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll dfs(ll now, vector<ll> e[], ll visited[], ll scc[], ll &visited_cnt, ll &scc_cnt, vector<ll> &path) {
  visited[now] = visited_cnt++;
  path.push_back(now);
  ll result = visited[now];
  for(ll next: e[now]) {
    if(visited[next] == -1) {
      result = min(result, dfs(next, e, visited, scc, visited_cnt, scc_cnt, path));
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T;
  cin >> T;
  while(T--) {
    ll N, M, A, B;
    cin >> N >> M;
    vector<ll> e[100100];
    for(ll i = 0; i < M; i++) {
      cin >> A >> B;
      e[A].push_back(B);
    }
    ll visited[100100];
    ll scc[100100];
    ll scc_cnt = 0;
    for(ll i = 0; i <= N; i++) {
      visited[i] = -1;
      scc[i] = -1;
    }
    for(ll i = 0; i < N; i++) {
      if(visited[i] == -1) {
        ll visited_cnt = 0;
        vector<ll> path;
        dfs(i, e, visited, scc, visited_cnt, scc_cnt, path);
      }
    }

    set<ll> scc_e[100100];
    for(ll now = 0; now < N; now++) {
      for(ll next: e[now]) {
        if(scc[now] != scc[next]) {
          scc_e[scc[now]].insert(scc[next]);
        }
      }
    }

    ll ind[100100];
    for(ll i = 0; i < scc_cnt; i++) {
      ind[i] = 0;
    }
    for(ll i = 0; i < scc_cnt; i++) {
      for(ll j: scc_e[i]) {
        ind[j]++;
      }
    }
    bool is_possible = true;
    for(ll 
    i = 0; i < scc_cnt; i++) {
      if(ind[i] == 0 && i != scc_cnt-1) {
        is_possible = false;
      }
    }
    
    if(is_possible) {
      for(ll i = 0; i < N; i++) {
        if(scc[i] == scc_cnt-1) {
          cout << i << '\n';
        }
      }
    } else {
      cout << "Confused" << '\n';
    }
    cout << '\n';
  }

  return 0;
}