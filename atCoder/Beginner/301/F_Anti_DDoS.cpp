#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998244353
typedef long long ll;
using namespace std;

string s;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;

  dp.assign(30, vector<ll>(s.size(), 0));
  if(s[0] == '?') {
    dp[0][0] = 26;
    for(ll i = 1; i <= 26; i++) dp[i][0] = 1;
  } else if(isupper(s[0])) {
    dp[s[0] - 'A' + 1][0] = 1;
  } else {
    dp[0][0] = 1;
  }

  for(ll i = 1; i < s.size(); i++) {
    if(s[i] == '?') {
      dp[0][i] = dp[0][i - 1] * 26 % MOD;
      for(ll j = 1; j <= 26; j++) {
        dp[j][i] = dp[0][i - 1] + dp[j][i - 1] * 51;
        dp[j][i] %= MOD;
        dp[27][i] += dp[j][i - 1];
        dp[27][i] %= MOD;
      }
      dp[27][i] += dp[27][i - 1] * 26;
      dp[27][i] %= MOD;
      dp[28][i] = dp[27][i - 1] * 26 + dp[28][i - 1] * 26;
      dp[28][i] %= MOD;

      dp[29][i] = dp[29][i - 1] * 52 + dp[28][i - 1] * 26;
      dp[29][i] %= MOD;
    } else if(isupper(s[i])) {
      dp[0][i] = 0;
      for(ll j = 1; j <= 26; j++) {
        if(s[i] == 'A' + j - 1) {
          dp[j][i] = dp[0][i - 1];
          dp[27][i] += dp[j][i - 1];
          dp[27][i] %= MOD;
        } else {
          dp[j][i] = dp[j][i - 1];
        }
      }
      dp[27][i] += dp[27][i - 1];
      dp[27][i] %= MOD;
      dp[28][i] = 0;

      dp[29][i] = dp[28][i - 1] + dp[29][i - 1];
      dp[29][i] %= MOD;
    } else {
      dp[0][i] = dp[0][i - 1];
      for(ll j = 1; j <= 26; j++) dp[j][i] = dp[j][i - 1];
      dp[27][i] = 0;
      dp[28][i] = dp[27][i - 1] + dp[28][i - 1];
      dp[28][i] %= MOD;

      dp[29][i] = dp[29][i - 1];
    }
  }

  #ifdef LOCAL
  for(ll i = 0; i < 30; i++) {
    for(ll j = 0; j < s.size(); j++) {
      cout.width(7);
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }
  #endif

  ll answer = 0;
  for(ll i = 0; i < 29; i++) {
    answer += dp[i][s.size() - 1];
    answer %= MOD;
  }

  cout << answer << '\n';

  
  return 0;
}