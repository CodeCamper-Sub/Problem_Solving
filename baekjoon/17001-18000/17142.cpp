#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<vector<ll>> grid;
vector<pair<ll, ll>> virus;
vector<bool> activated;
vector<vector<ll>> visited;

ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

ll bfs() {
  visited.assign(n, vector<ll>(n, INF));
  queue<pair<ll, ll>> q;
  for(ll i = 0; i < virus.size(); i++) {
    if(activated[i]) {
      visited[virus[i].first][virus[i].second] = 0;
      q.push(virus[i]);
    }
  }
  while(q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny < 0 || ny >= n || nx < 0 || nx >= n || grid[ny][nx] == 1 || visited[ny][nx] <= visited[y][x] + 1) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
  ll result = 0;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      if(grid[i][j] != 0) continue;
      result = max(result, visited[i][j]);
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 2) virus.push_back({i, j});
    }
  }

  for(ll i = 0; i < ll(virus.size()) - m; i++) activated.push_back(false);
  for(ll i = 0; i < m; i++) activated.push_back(true);

  ll answer = INF;
  do {
    answer = min(answer, bfs());
  } while(next_permutation(activated.begin(), activated.end()));

  if(answer == INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}