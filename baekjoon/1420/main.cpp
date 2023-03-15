#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 110
#define MAX_NODE (2 * MAX * MAX)
typedef long long ll;
using namespace std;

struct Edge {
  ll next, capacity, flow, rev;

  Edge(ll n, ll c, ll f, ll r): next(n), capacity(c), flow(f), rev(r) {}
};

ll n, m, source, sink, level[MAX_NODE], work[MAX_NODE], max_flow;
char grid[MAX][MAX];
vector<Edge> e[MAX_NODE];
ll dy[4] = {1, 0, 0, -1};
ll dx[4] = {0, 1, -1, 0};

ll flatten(ll y, ll x) {
  return (y * m) + x;
}

ll input(ll y, ll x) {
  return flatten(y, x) + (n * m);
}

ll input(ll now) {
  return now + (n * m);
}

void make_edge(ll now, ll next, ll capacity) {
  e[now].push_back({next, capacity, 0, ll(e[next].size())});
  e[next].push_back({now, 0, 0, ll(e[now].size() - 1)});
}

bool get_level_graph() {
  fill(level, level + MAX_NODE, -1);
  queue<ll> q;
  level[source] = 0;
  q.push(source);
  while(q.size()) {
    ll now = q.front();
    q.pop();
    for(auto [next, capacity, flow, rev]: e[now]) {
      if(level[next] == -1 && capacity - flow > 0) {
        level[next] = level[now] + 1;
        q.push(next);
      }
    }
  }

  return level[sink] != -1;
}

ll send_flow(ll now, ll min_flow) {
  if(now == sink) return min_flow;
  for(ll &i = work[now]; i < e[now].size(); i++) {
    auto [next, capacity, flow, rev] = e[now][i];
    if(level[now] + 1 == level[next] && capacity - flow > 0) {
      ll result = send_flow(next, min(min_flow, capacity - flow));
      if(result > 0) {
        e[now][i].flow += result;
        e[next][rev].flow -= result;
        return result;
      }
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 0 ; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'K') {
        source = flatten(i, j);
      } else if(grid[i][j] == 'H') {
        sink = flatten(i, j);
      }
    }
  }

  // input 노드와 output노드 연결하기
  for(ll y = 0; y < n; y++) {
    for(ll x = 0; x < m; x++) {
      if(grid[y][x] == '.') {
        make_edge(input(y, x), flatten(y, x), 1);
      } else if(grid[y][x] == 'H') {
        make_edge(input(y, x), flatten(y, x), INF);
      }
    }
  }

  // output 노드와 상하좌우 노드의 input 노드 연결
  for(ll y = 0; y < n; y++) {
    for(ll x = 0; x < m; x++) {
      if(grid[y][x] == '#') continue;
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny < n && ny >= 0 && nx < m && nx >= 0 && grid[ny][nx] != '#') {
          make_edge(flatten(y, x), input(ny, nx), INF);
        }
      }
    }
  }

  max_flow = 0;
  while(get_level_graph()) {
    if(level[sink] == 2) break;
    while(true) {
      fill(work, work + MAX_NODE, 0);
      ll result = send_flow(source, INF);
      if(result == 0) break;
      max_flow += result;
    }
  }

  if(level[sink] == 2) {
    cout << -1 << '\n';
  } else {
    cout << max_flow << '\n';
  }
  
  return 0;
}