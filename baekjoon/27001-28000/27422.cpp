#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll h, w, source, sink;
vector<vector<char>> grid;
vector<vector<ll>> e;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};
vector<ll> dist_from_source, dist_from_sink;
vector<vector<ll>> sparse;
vector<ll> level;

ll flatten(ll y, ll x) {
  return y * w + x;
}

void get_dist(ll now, ll parent, vector<ll>& dist) {
  for(ll next: e[now]) {
    if(next == parent) continue;
    dist[next] = dist[now] + 1;
    get_dist(next, now, dist);
  }
}

void get_parent(ll now, ll parent) {
  for(ll next: e[now]) {
    if(next == parent) continue;
    sparse[0][next] = now;
    level[next] = level[now] + 1;
    get_parent(next, now);
  }
}

ll set_level(ll a, ll to_level) {
  ll delta = level[a] - to_level;
  if(delta <= 0) return a;
  for(ll i = 25; i >= 0; i--) {
    if(delta >= (1ll << i)) {
      delta -= (1ll << i);
      a = sparse[i][a];
    }
  }
  return a;
}

ll lca(ll a, ll b) {
  a = set_level(a, min(level[a], level[b]));
  b = set_level(b, min(level[a], level[b]));
  if(a == b) return a;
  for(ll i = 25; i >= 0; i--) {
    if(sparse[i][a] != sparse[i][b]) {
      a = sparse[i][a];
      b = sparse[i][b];
    }
  }
  return sparse[0][a];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  source = 0;
  sink = h * w - 1;
  grid.assign(2 * h + 1, vector<char>(2 * w + 1));
  e.resize(h * w);
  for(ll i = 0; i < 2 * h + 1; i++) {
    for(ll j = 0; j < 2 * w + 1; j++) {
      cin >> grid[i][j];
    }
  }

  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      ll y = 2 * i + 1;
      ll x = 2 * j + 1;
      for(ll k = 0; k < 4; k++) {
        ll ni = i + dy[k], nj = j + dx[k];
        ll ny = y + dy[k], nx = x + dx[k];
        if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if(grid[ny][nx] == '.') {
          e[flatten(i, j)].push_back(flatten(ni, nj));
        }
      }
    }
  }

  dist_from_source.resize(h * w);
  dist_from_sink.resize(h * w);
  dist_from_source[source] = 0;
  get_dist(source, -1, dist_from_source);
  dist_from_sink[sink] = 0;
  get_dist(sink, -1, dist_from_sink);

  sparse.assign(26, vector<ll>(h * w));
  level.resize(h * w);
  sparse[0][source] = source;
  level[source] = 0;
  get_parent(source, -1);
  for(ll i = 1; i < 26; i++) {
    for(ll j = 0; j < h * w; j++) {
      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  ll answer = 0;
  for(ll y = 0; y < h; y++) {
    for(ll x = 0; x < w; x++) {
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        ll l = lca(flatten(y, x), sink);
        if(lca(flatten(y, x), flatten(ny, nx)) == l || lca(flatten(ny, nx), sink) == l) continue;
        answer = max(answer, dist_from_sink[flatten(y, x)] + dist_from_source[flatten(ny, nx)] + 2);
      }
    }
  }

  cout << answer << '\n';

  return 0;
}