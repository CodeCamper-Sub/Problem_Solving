#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll V, E, A, B, visited_cnt;
vector<ll> e[10100];
vector<ll> path;
ll visited[10100];
bool included_in_scc[10100];

vector<set<ll>> sccs;

bool compare(const set<ll> a, const set<ll> b) {
  return *(a.begin()) <= *(b.begin());
}

// 타잔 알고리즘
ll dfs(ll now) {
  path.push_back(now);
  visited[now] = visited_cnt++;
  ll result = visited[now];
  for(ll i = 0; i < e[now].size(); i++) {
    ll next = e[now][i];
    if(visited[next] == -1) {
      result = min(result, dfs(next));
    } else if(!included_in_scc[next]) {
      result = min(result, visited[next]);
    }
  }
  if(visited[now] == result) {
    set<ll> scc;
    while(!path.empty()) {
      ll node = path.back(); 
      path.pop_back();
      included_in_scc[node] = true;
      scc.insert(node);
      if(node == now) break;
    }
    sccs.push_back(scc);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> V >> E;
  for(ll i = 0; i < E; i++) {
    cin >> A >> B;
    e[A].push_back(B);
  }
  for(ll i = 1; i <= V; i++) {
    visited[i] = -1;
    included_in_scc[i] = false;
  }
  for(ll i = 1; i <= V; i++) {
    if(visited[i] == -1) {
      dfs(i);
    }
  }
  sort(sccs.begin(), sccs.end(), compare);
  cout << sccs.size() << '\n';
  for(set<ll> scc: sccs) {
    for(ll node: scc) {
      cout << node << ' ';
    }
    cout << "-1\n";
  }

  return 0;
}