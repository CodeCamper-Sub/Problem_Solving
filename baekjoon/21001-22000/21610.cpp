#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
ll dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

ll n, m, d, s;
vector<vector<ll>> grid, can_make_cloud;
vector<pair<ll, ll>> clouds;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<ll>(n));
  can_make_cloud.assign(n, vector<ll>(n, true));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> grid[i][j];

  clouds.push_back({n - 1, 0});
  clouds.push_back({n - 1, 1});
  clouds.push_back({n - 2, 0});
  clouds.push_back({n - 2, 1});

  while(m--) {
    cin >> d >> s;
    for(auto& [y, x]: clouds) {
      y = y + dy[d - 1] * s;
      x = x + dx[d - 1] * s;
      y = (y + n * 100) % n;
      x = (x + n * 100) % n;
      grid[y][x] += 1;
      can_make_cloud[y][x] = false;
    }

    for(auto [y, x]: clouds) {
      ll cnt = 0;
      for(ll k = 1; k < 8; k += 2) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if(grid[ny][nx] > 0) cnt++;
      }
      grid[y][x] += cnt;
    }

    clouds.clear();
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        if(grid[i][j] >= 2 && can_make_cloud[i][j]) {
          grid[i][j] -= 2;
          clouds.push_back({i, j});
        }
        can_make_cloud[i][j] = true;
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
    answer += grid[i][j];
  }

  cout << answer << '\n';
  
  return 0;
}