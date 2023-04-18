#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<ll>> dp;
vector<vector<ll>> grid;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  // 현재 보고 있는 칸의 왼쪽 칸부터 바로 아래에 있는 칸까지의 상태값을 저장함.
  dp.assign(n * m + 1, vector<ll>((1ll << (m + 2))));
  grid.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin >> grid[i][j];
  if(n == 1 || m == 1) {
    cout << 0 << '\n';
    return 0;
  }
  for(ll i = 0; i < n * m; i++) {
    ll y = i / m;
    ll x = i % m;
    for(ll status = 0; status < (1ll << (m + 2)); status++) {
      // *(*)
      // *
      ll status_condition = (1ll << 0) | (1ll << 1) | (1ll << m);
      if(y < n - 1 && x > 0 && !(status & status_condition)) {
        ll next_status = (status | status_condition) >> 1;
        ll score = grid[y][x] + grid[y][x - 1] * 2 + grid[y + 1][x - 1];
        dp[i + 1][next_status] = max(dp[i + 1][next_status], dp[i][status] + score);
      }
      
      //  (*)
      // * *
      status_condition = (1ll << 1) | (1ll << m) | (1ll << (m + 1));
      if(y < n - 1 && x > 0 && !(status & status_condition)) {
        ll next_status = (status | status_condition) >> 1;
        ll score = grid[y][x] + grid[y + 1][x] * 2 + grid[y + 1][x - 1];
        dp[i + 1][next_status] = max(dp[i + 1][next_status], dp[i][status] + score);
      }

      //(*)
      // * *
      status_condition = (1ll << 1) | (1ll << (m + 1)) | (1ll << (m + 2));
      if(y < n - 1 && x < m - 1 && !(status & status_condition)) {
        ll next_status = (status | status_condition) >> 1;
        ll score = grid[y][x] + grid[y + 1][x] * 2 + grid[y + 1][x + 1];
        dp[i + 1][next_status] = max(dp[i + 1][next_status], dp[i][status] + score);
      }

      //(*)*
      //   *
      status_condition = (1ll << 1) | (1ll << 2) | (1ll << (m + 2));
      if(y < n - 1 && x < m - 1 && !(status & status_condition)) {
        ll next_status = (status | status_condition) >> 1;
        ll score = grid[y][x] + grid[y][x + 1] * 2 + grid[y + 1][x + 1];
        dp[i + 1][next_status] = max(dp[i + 1][next_status], dp[i][status] + score);
      }

      // 그냥 넘기기
      ll next_status = status >> 1;
      dp[i + 1][next_status] = max(dp[i + 1][next_status], dp[i][status]);
    }
  }


  cout << max(dp[n * m][0], dp[n * m][1]) << '\n';
  
  return 0;
}