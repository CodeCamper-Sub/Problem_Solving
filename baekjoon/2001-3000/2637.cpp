#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, X, Y, K;
vector<pair<ll, ll>> e[110];
ll depth[110], dp[110];

ll dfs(ll now) {
  if(depth[now] != -1) return depth[now];
  depth[now] = 0;
  for(pair<ll, ll> p: e[now]) {
    ll next = p.first;
    depth[now] = max(depth[now], dfs(next) + 1);
  }
  return depth[now];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(ll i = 0; i < M; i++) {
    cin >> X >> Y >> K;
    e[X].push_back({Y, K});
  }
  fill(depth, depth + N + 1, -1);
  dfs(N);
  dp[N] = 1;
  for(ll i = depth[N]; i > 0; i--) {
    for(ll j = 1; j <= N; j++) {
      if(depth[j] == i) {
        for(pair<ll, ll> p: e[j]) {
          dp[p.first] += p.second * dp[j];
        }
        dp[j] = 0;
      }
    }
  }
  for(ll i = 1; i <= N; i++) {
    if(dp[i] > 0) {
      cout << i << ' ' << dp[i] << '\n';
    }
  }


  return 0;
}