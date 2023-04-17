#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll h, w, days;
vector<vector<ll>> grid;
ll dy[8] = {0, 0, 1, 1, 1, -1, -1, -1};
ll dx[8] = {1, -1, 1, 0, -1, 1, 0, -1};
queue<pair<ll, ll>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  grid.assign(h, vector<ll>(w));
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      char tmp;
      cin >> tmp;
      if(tmp == '.') grid[i][j] = -1;
      else grid[i][j] = tmp - '0';
    }
  }

  for(ll i = 1; i < h - 1; i++) {
    for(ll j = 1; j < w - 1; j++) {
      if(grid[i][j] == -1) continue;
      ll cnt = 0;
      for(ll k = 0; k < 8; k++) {
        ll ny = i + dy[k], nx = j + dx[k];
        if(grid[ny][nx] == -1) {
          cnt++;
        }
      }
      if(grid[i][j] <= cnt) {
        grid[i][j] = 0;
        q.push({i, j});
      } else {
        grid[i][j] -= cnt;
      }
    }
  }

  while(q.size()) {
    days++;
    ll n = q.size();
    while(n--) {
      auto [y, x] = q.front();
      q.pop();
      for(ll k = 0; k < 8; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(grid[ny][nx] == 0 || grid[ny][nx] == -1) continue;
        else if(grid[ny][nx] == 1) {
          q.push({ny, nx});
        }
        grid[ny][nx] -= 1;
      }
    }
  }

  cout << days << '\n';
  
  return 0;
}