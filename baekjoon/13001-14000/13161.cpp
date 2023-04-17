#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 550
typedef long long ll;
using namespace std;

ll n, k, source, sink, cost[MAXN][MAXN], capacity[MAXN][MAXN], flow[MAXN][MAXN], visited[MAXN], level[MAXN], max_flow, work[MAXN];
vector<ll> a_elements, neut_elements, b_elements, e[MAXN];

bool get_level_graph() {
  fill(level, level + MAXN, -1);
  queue<ll> q;
  level[source] = 0;
  q.push(source);
  while(!q.empty()) {
    ll now = q.front(); 
    q.pop();
    for(ll next: e[now]) {
      if(level[next] == -1 && capacity[now][next] - flow[now][next] > 0) {
        level[next] = level[now] + 1;
        q.push(next);
      }
    }
  }

  return level[sink] != -1;
}

ll dinic_dfs(ll now, ll min_flow) {
  if(now == sink) {
    return min_flow;
  }
  // for(ll next: e[now]) {
  for(ll &i = work[now]; i < e[now].size(); i++) {
    ll next = e[now][i];
    if(level[now] + 1 == level[next] && capacity[now][next] - flow[now][next] > 0) {
      ll result = dinic_dfs(next, min(min_flow, capacity[now][next] - flow[now][next]));
      if(result > 0) {
        flow[now][next] += result;
        flow[next][now] -= result;
        return result;
      }
    }
  }

  return 0;
}

ll dinic_bfs() {
  ll result = 0, visited[MAXN];
  while)true) {
    fill(visited, visited + MAXN, -1);
  }
}

void dinic() {
  max_flow = 0;
  while(get_level_graph()) {
    fill(work, work + MAXN, 0);
    while(true) {
      ll result = dinic_dfs(source, INF);
      if(result == 0) break;
      max_flow += result;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 1; i <= n; i++) {
    cin >> k;
    if(k == 1) {
      a_elements.push_back(i);
    } else if(k == 2) {
      b_elements.push_back(i);
    } else {
      neut_elements.push_back(i);
    }
  }

  for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) {
    cin >> capacity[i][j];
    if(i != j) {
      e[i].push_back(j);
    }
  }

  source = n + 1;
  sink = n + 2;

  for(ll a: a_elements) {
    e[source].push_back(a);
    e[a].push_back(source);
    capacity[source][a] = INF;
  }

  for(ll b: b_elements) {
    e[b].push_back(sink);
    e[sink].push_back(b);
    capacity[b][sink] = INF;
  }

  dinic();

  cout << max_flow << '\n';
  for(ll i = 1; i <= n; i++) {
    if(level[i] != -1) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  for(ll i = 1; i <= n; i++) {
    if(level[i] == -1) {
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}