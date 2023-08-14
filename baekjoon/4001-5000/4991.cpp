#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, sy, sx;
vector<vector<char>> grid;
map<pair<ll, ll>, ll> trashes;
vector<vector<vector<ll>>> visited;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

bool init() {
  cin >> m >> n;
  if(n == 0 && m == 0) return false;
  
  trashes.clear();
  grid.assign(n, vector<char>(m));
  ll trash_id = 0;
  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) {
    cin >> grid[i][j];
    if(grid[i][j] == '*') trashes[{i, j}] = trash_id++;
    else if(grid[i][j] == 'o') { 
      sy = i; sx = j;
      grid[i][j] = '.';
    }
  }

  return true;
}

void solve() {
  visited.resize(1ll << ll(trashes.size()));
  for_each(visited.begin(), visited.end(), [](auto& layer) {
    layer.assign(n, vector<ll>(m, INF));
  });

  visited[0][sy][sx] = 0;
  queue<tuple<ll, ll, ll>> q;
  q.push({0, sy, sx});
  while(q.size()) {
    auto [status, y, x] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == 'x') continue;
      ll next_status = status;
      if(grid[ny][nx] == '*') {
        next_status |= (1ll << trashes[{ny, nx}]);
      }
      if(visited[next_status][ny][nx] > visited[status][y][x] + 1) {
        visited[next_status][ny][nx] = visited[status][y][x] + 1;
        if(next_status != (1ll << ll(trashes.size())) - 1) {
          q.push({next_status, ny, nx});
        }
      }
    }
  }

  ll answer = INF;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      answer = min(answer, visited[(1ll << ll(trashes.size())) - 1][i][j]);
    }
  }

  if(answer != INF) {
    cout << answer << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(true) {
    if(!init()) break;
    solve();
  }
  return 0;
}