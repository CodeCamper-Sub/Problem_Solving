#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<vector<char>> grid;
vector<vector<vector<ll>>> visited;
const ll n = 8, m = 8;
const pair<ll, ll> source = {7, 0}, sink = {0, 7};
ll dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
ll dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  grid.assign(n, vector<char>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  visited.resize(30);
  for_each(visited.begin(), visited.end(), [](auto& layer) { layer.assign(n, vector<ll>(m, false)); });

  visited[0][source.first][source.second] = true;
  queue<tuple<ll, ll, ll>> q;
  q.push({0, source.first, source.second});

  bool answer = false;
  while(q.size()) {
    auto [dist, y, x] = q.front();
    q.pop();
    if(y - dist >= 0 && grid[y - dist][x] == '#') continue;
    for(ll k = 0; k < 9; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m || (ny - dist >= 0 && grid[ny - dist][nx] == '#') || visited[dist + 1][ny][nx]) continue;
      if(ny == sink.first && nx == sink.second) {
        answer = true;
        break;
      }
      visited[dist + 1][ny][nx] = true;
      q.push({dist + 1, ny, nx});
    }
    if(answer) break;
  }

  cout << (answer ? 1 : 0) << '\n';
  
  return 0;
}