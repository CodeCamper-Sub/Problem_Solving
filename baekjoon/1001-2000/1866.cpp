#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, truck, heli;
vector<ll> courier, dp;
vector<vector<ll>> psum; // psum[i][j] i에서 출발해서 i~j 사이에 있는 택배들을 배송하는 총 비용

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  courier.resize(n);
  dp.assign(n, INF);
  psum.resize(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) cin >> courier[i];
  cin >> truck >> heli;
  sort(courier.begin(), courier.end());

  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      psum[i][j] = psum[i][j - 1] + (courier[j] - courier[i]) * truck;
    }
    for(ll j = i - 1; j >= 0; j--) {
      psum[i][j] = psum[i][j + 1] + (courier[i] - courier[j]) * truck;
    }
  }

  dp[0] = min(courier[0] * truck, heli);
  for(ll i = 1; i < n; i++) {
    for(ll j = i; j >= 0; j--) {
      dp[i] = min(dp[i], min(dp[i - 1] + courier[i] * truck, (j > 0 ? dp[j - 1] : 0) + heli + psum[(i + j) / 2][j] + psum[(i + j) / 2][i]));
    }
  }

  cout << dp[n - 1] << '\n';

  
  
  return 0;
}