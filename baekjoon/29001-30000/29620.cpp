#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9 + 7)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, x, y;
vector<vector<char>> grid;
vector<vector<vector<vector<ll>>>> dp;

bool should_insert_B(ll y, ll x, ll status) {
  ll result = true;
  if(y == 0) result = false;
  if(!(status & (1ll << m))) result = false;
  if(y - 2 >= 0 && (status & (1ll << 0))) result = false;
  if(x - 1 >= 0 && (status & (1ll << (m - 1)))) result = false;
  if(x + 1 < m && (status & (1ll << (m + 1)))) result = false;

  if(y < n - 1 || result) return result;
  
  result = true;
  if(x == 0) result = false;
  if(!(status & (1ll << (2 * m - 1)))) result = false;
  if(x - 2 >= 0 && (status & (1ll << (2 * m - 2)))) result = false;
  if(x - 1 >= 0 && y - 1 >= 0 && (status & (1ll << (m - 1)))) result = false;

  return result;
}

bool can_insert_B(ll y, ll x, ll status) {
  if(grid[y][x] == 'A') return false;
  if(y - 1 >= 0 && grid[y - 1][x] == 'A') return false;
  if(x + 1 < m && grid[y][x + 1] == 'A') return false;
  if(y + 1 < n && grid[y + 1][x] == 'A') return false;
  if(x - 1 >= 0 && grid[y][x - 1] == 'A') return false;
  if(y != n - 1 || x != m - 1) return true;

  if(x - 1 >= 0 && (status & (1ll << (2 * m - 1)))) return true;
  if(y - 1 >= 0 && (status & (1ll << m))) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> x >> y;
  grid.assign(n, vector<char>(m));

  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin >> grid[i][j];
  dp.resize(n + 1);
  for_each(dp.begin(), dp.end(), [](auto& cube) {
    cube.resize(m + 1);
    for_each(cube.begin(), cube.end(), [](auto& layer) {
      layer.assign(1ll << (2 * m), vector<ll>(x + 1, 0));
    });
  });

  dp[0][0][0][0] = 1;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      for(ll status = 0; status < (1ll << (2 * m)); status++) {
        for(ll k = 0; k <= x; k++) {
          if(!dp[i][j][status][k]) continue;
          if(should_insert_B(i, j, status) && (!can_insert_B(i, j, status) || k == x)) continue;
          // 인싸 안 넣기
          // 인싸를 꼭 넣어야 하는 상황
          if(!should_insert_B(i, j, status)) {
            ll next_status = (status) >> 1;
            ll ny = i, nx = j + 1;
            if(nx >= m) {
              nx = 0;
              ny++;
            }
            dp[ny][nx][next_status][k] += dp[i][j][status][k];
            dp[ny][nx][next_status][k] %= MOD;
          }

          // 인싸 넣기
          if(k < x && can_insert_B(i, j, status)) {
            ll next_status = (status) >> 1;
            next_status |= (1ll << (2 * m - 1));
            ll ny = i, nx = j + 1;
            if(nx >= m) {
              nx = 0;
              ny++;
            }
            dp[ny][nx][next_status][k + 1] += dp[i][j][status][k];
            dp[ny][nx][next_status][k + 1] %= MOD;
          }
        }
      }
    }
  }

  ll answer = 0;
  for(ll status = 0; status < (1ll << (2 * m)); status++) {
    answer += dp[n][0][status][x];
    answer %= MOD;
  }

  cout << answer << '\n';
  
  return 0;
}