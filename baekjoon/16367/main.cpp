#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll k, n, l, visited[10100], visited_cnt, scc[10100], scc_cnt, state[10100];
char c;
vector<ll> e[10100], scc_nodes[10100];
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
      ll node = path.top();
      path.pop();
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

  cin >> k >> n;
  for(ll i = 0; i < n; i++) {
    vector<ll> paper;
    for(ll j = 0; j < 3; j++) {
      cin >> l >> c;
      if(c == 'R') paper.push_back(l);
      else paper.push_back(-l);
    }
    e[-paper[0] + k].push_back(paper[1] + k);
    e[-paper[0] + k].push_back(paper[2] + k);

    e[-paper[1] + k].push_back(paper[0] + k);
    e[-paper[1] + k].push_back(paper[2] + k);

    e[-paper[2] + k].push_back(paper[0] + k);
    e[-paper[2] + k].push_back(paper[1] + k);
  }

  fill(visited, visited + 2 * k + 1, -1);
  visited_cnt = 0;
  fill(scc, scc + 2 * k + 1, -1);
  scc_cnt = 0;
  for(ll i = 0; i <= 2 * k; i++) {
    if(visited[i] == -1)
      dfs(i);
  }

  bool is_possible = true;
  for(ll i = 0; i < k; i++) {
    if(scc[i] == scc[2 * k - i]){
      is_possible = false;
      break;
    }
  }

  if(!is_possible) {
    cout << -1 << '\n';
    return 0;
  }

  fill(state, state + 2 * k + 1, -1);
  for(ll i = scc_cnt - 1; i >= 0; i--) {
    for(ll node: scc_nodes[i]) {
      if(state[node] == -1) {
        state[node] = 0;
        ll matched_node = 2 * k - node;
        state[matched_node] = 1;
      }
    }
  }

  for(ll i = k + 1; i <= 2 * k; i++) {
    if(state[i]) {
      cout << "R";
    } else {
      cout << "B";
    }
  }

  return 0;
}