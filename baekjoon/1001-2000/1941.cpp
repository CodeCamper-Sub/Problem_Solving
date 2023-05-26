#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> selected_grid;
vector<vector<bool>> visited;
vector<ll> selected;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  grid.assign(5, vector<char>(5));
  for(ll i = 0; i < 5; i++) {
    for(ll j = 0; j < 5; j++) {
      cin >> grid[i][j];
    }
  }

  for(ll i = 0; i < 18; i++) selected.push_back(0);
  for(ll i = 0; i < 7; i++) selected.push_back(1);

  ll answer = 0;
  do {
    selected_grid.assign(5, vector<bool>(5, false));
    visited.assign(5, vector<bool>(5, false));
    for(ll i = 0; i < selected.size(); i++) {
      if(selected[i]) {
        selected_grid[i / 5][i % 5] = true;
      }
    }
    queue<pair<ll, ll>> q;
    ll s_cnt = 0, y_cnt = 0;
    for(ll i = 0; i < 5; i++) {
      for(ll j = 0; j < 5; j++) {
        if(selected_grid[i][j]) {
          visited[i][j] = true;
          q.push({i, j});
          break;
        }
      }
      if(q.size()) break;
    }
    while(q.size()) {
      auto [y, x] = q.front();
      q.pop();
      if(grid[y][x] == 'S') s_cnt++;
      else y_cnt++;
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx] || !selected_grid[ny][nx]) continue;
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
    if(s_cnt + y_cnt == 7 && s_cnt > y_cnt)
      answer++;
  } while(next_permutation(selected.begin(), selected.end()));
  
  cout << answer << '\n';

  return 0;
}