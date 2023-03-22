#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 60
#define MAX (MAXN * MAXN)
typedef long long ll;
using namespace std;

ll tt, n, m, sum, grid[MAXN][MAXN], source, sink, c[MAX][MAX], f[MAX][MAX],
    level[MAX], work[MAX];
vector<ll> e[MAX];
ll dy[4] = {1, 0, 0, -1};
ll dx[4] = {0, 1, -1, 0};

ll flatten(ll y, ll x) { return y * m + x; }

void create_edge(ll now, ll next, ll capacity = INF) {
  e[now].push_back(next);
  e[next].push_back(now);
  c[now][next] += capacity;
}

bool get_level_graph() {
  fill(level, level + MAX, -1);
  queue<ll> q;
  level[source] = 0;
  q.push(source);
  while(q.size()) {
    ll now = q.front();
    q.pop();
    for(ll next: e[now]) {
      if(level[next] == -1 && c[now][next] - f[now][next] > 0) {
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
    ll next = e[now][i];
    if(level[now] + 1 == level[next] && c[now][next] - f[now][next]) {
      ll result = send_flow(next, min(min_flow, c[now][next] - f[now][next]));
      if(result > 0) {
        f[now][next] += result;
        f[next][now] -= result;
        return result;
      }
    }
  }
  return 0;
}

void solve() {
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> grid[i][j];
      sum += grid[i][j];
    }
  }
  for (ll y = 0; y < n; y++) {
    for (ll x = y % 2; x < m; x += 2) {
      create_edge(source, flatten(y, x), grid[y][x]);
      for (ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if (ny < n && ny >= 0 && nx < m && nx >= 0) {
          create_edge(flatten(y, x), flatten(ny, nx));
        }
      }
    }
    for(ll x = y % 2 ^ 0 ^ 1; x < m; x += 2) {
      create_edge(flatten(y, x), sink, grid[y][x]);
    }
  }

  ll total_flow = 0;
  while(get_level_graph()) {
    fill(work, work + MAX, 0);
    while(true) {
      ll partial_flow = send_flow(source, INF);
      if(partial_flow == 0) break;
      total_flow += partial_flow;
    }
  }

  #ifdef DEBUG
  cout << "\nAns: ";
  #endif
  cout << sum - total_flow << '\n';
}

void init() {
  cin >> n >> m;
  for (ll i = 0; i < n * m + 2; i++) {
    e[i].clear();
  }
  fill(&c[0][0], &c[n * m + 2][MAX], 0);
  fill(&f[0][0], &f[n * m + 2][MAX], 0);
  source = n * m;
  sink = n * m + 1;
  sum = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while (tt--) {
    init();
    solve();
  }

  return 0;
}