#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll N, M;

char arr[100];
ll arrs[100];

ll dp[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (ll i = 1; i <= N; i++) {
    cin >> arr[i] >> arrs[i];
  }
  dp[N + 1] = 1;
  ll q = 1;
  ll ans = 0;
  for (ll i = N; i >= 1; i--) {
    if (arr[i] == 'G' || arrs[i] == 1) {
      ans += dp[i + 1] * arrs[i];
      dp[i] = dp[i + 1] * 2;
    } else if (arr[i] == 'R') {
      if (dp[i + 1] % 2 == 1) {
        ans += dp[i + 1] * arrs[i];
        dp[i] = dp[i + 1] * 2;
      } else {
        ans += (dp[i + 1] + 1) * arrs[i];
        dp[i] = dp[i + 1] * 2 + 1;
        if(i==1 && arrs[i] > 1) ans--;
      }
    } else if (arr[i] == 'B') {
      if (dp[i + 1] % 2 == 1) {
        ans += (dp[i + 1] + 1) * arrs[i];
        dp[i] = dp[i + 1] * 2 + 1;
        if(i==1 && arrs[i] > 1) ans--;
      } else {
        ans += dp[i + 1] * arrs[i];
        dp[i] = dp[i + 1] * 2;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}