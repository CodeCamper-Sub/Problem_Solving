#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, A, B, S, P, p, visited_cnt, scc_cnt;
ll money[500500], visited[500500], scc[500500], scc_money[500500], maximum[500500], scc_memo[500500];
vector<ll> e[500500];
set<ll> scc_e[500500];
vector<ll> path;
bool restaurant[500500], scc_restaurant[500500];

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

ll scc_dfs(ll now) {
  if(scc_memo[now] != -1) return scc_memo[now];
  ll result = 0;
  for(ll next: scc_e[now]) {
    result = max(result, scc_dfs(next));
  }
  if(result > 0 || scc_restaurant[now]) {
    return scc_memo[now] = result + scc_money[now];
  } else {
    return scc_memo[now] = 0;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> M;

  for(ll i = 0; i < M; i++) {
    cin >> A >> B;
    e[A].push_back(B);
  }

  for(ll i = 1; i <= N; i++) {
    cin >> money[i];
  }

  cin >> S >> P;
  for(ll i = 0; i < P; i++) {
    cin >> p;
    restaurant[p] = true;
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
    if(scc[now] == -1) continue;
    for(ll next: e[now]) {
      if(scc[next] == -1) continue;
      if(scc[now] != scc[next]) {
        scc_e[scc[now]].insert(scc[next]);
      }
    }
    scc_money[scc[now]] += money[now];
    scc_restaurant[scc[now]] |= restaurant[now];
  }

  for(ll i = 0; i <= scc_cnt; i++) {
    scc_memo[i] = -1;
  }
  
  cout << scc_dfs(scc[S]) << '\n';

  return 0;
}