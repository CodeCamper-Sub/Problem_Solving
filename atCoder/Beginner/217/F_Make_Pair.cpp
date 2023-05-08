#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, m, a, b;
vector<vector<ll>> e;
vector<vector<vector<ll>>> dp; // 0 한 덩어리 1 쪼개는 경우

void divide_conquer(ll start, ll end) {
  if(dp[0][start][end] != -1) return;
  if((end - start) % 2 == 0) {
    dp[0][start][end] = 0;
    dp[1][start][end] = 0;
    return;
  }
  dp[0][start][end] = 0;
  dp[1][start][end] = 0;
  for(ll next: e[start]) {
    if(next > end) break;
    if(start + 1 == end && next == end) {
      dp[0][start][end] = 1;
      dp[1][start][end] = 0;
      return;
    }
    ll partial_answer = 1;
    if(next == end) {
      if(start + 1 == end) {
        dp[0][start][end] += 1;
      } else {
        divide_conquer(start + 1, end - 1);
        dp[0][start][end] += dp[0][start + 1][end - 1] + dp[1][start + 1][end - 1];
      }
      dp[0][start][end] %= MOD;
    } else {
      divide_conquer(start, next);
      divide_conquer(next + 1, end);
      dp[1][start][end] += 2 * dp[0][start][next] * dp[0][next + 1][end];
      dp[1][start][end] %= MOD;
      dp[1][start][end] += 3 * dp[1][start][next] * dp[0][next + 1][end];
      dp[1][start][end] %= MOD;
      dp[1][start][end] += 3 * dp[0][start][next] * dp[1][next + 1][end];
      dp[1][start][end] %= MOD;
      dp[1][start][end] += 6 * dp[1][start][next] * dp[1][next + 1][end];
      dp[1][start][end] %= MOD;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(2 * n + 1);
  dp.resize(2);
  for_each(dp.begin(), dp.end(), [](auto& layer) {
    layer.assign(2 * n + 1, vector<ll>(2 * n + 1, -1));
  });
  for(ll i = 0; i < m; i++) {
    cin >> a >> b;
    if(a > b) swap(a, b);
    e[a].push_back(b);
  }
  for(ll i = 1; i <= 2 * n; i++) {
    sort(e[i].begin(), e[i].end());
  }

  divide_conquer(1, 2 * n);
  cout << (dp[0][1][2 * n] + dp[1][1][2 * n]) << '\n';
  
  return 0;
}