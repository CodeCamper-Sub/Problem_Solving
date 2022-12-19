#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, W[20][20];
ll dp[20][1<<17];

ll dfs(ll city, ll status) {
  if(status == (1 << N) - 1) return dp[city][status] = W[city][0];
  if(dp[city][status] != 0) return dp[city][status];

  dp[city][status] = INF;
  for(ll i = 0; i < N; i++) {
    if(status & (1 << i)) continue;
    if(W[city][i] == INF) continue;
    dp[city][status] = min(dp[city][status], dfs(i, status | (1 << i)) + W[city][i]);
  }
  return dp[city][status];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
    cin >> W[i][j];
    if(W[i][j] == 0) W[i][j] = INF;
  }
  
  cout << dfs(0, 1) << '\n';
  
  return 0;
}