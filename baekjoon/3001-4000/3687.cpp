#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 110
typedef long long ll;
using namespace std;

ll tt, n; // dp[i][j]: i개를 전부 사용해 성냥개비로 만들 수 있는 j자리의 수 중에서 가장 작은 수
string dp[MAX][MAX];

string get_max(ll n) {
  string result;
  if (n % 2) {
    result = "7";
    n -= 3;
  }
  for (ll i = 0; i < (n / 2); i++) {
    result += "1";
  }
  return result;
}

string get_min(ll n) {
  for(ll i = 0; i <= 100; i++) {
    if(dp[n][i] != "INF") {
      return dp[n][i];
    }
  }
}

void solve() {
  cin >> n;

  cout << get_min(n) << ' ' << get_max(n) << '\n';
}

string get_min_dp_value(ll i, ll j, string num) {
  string result = "A";
  if(num != "0" || dp[i][j].size() > 0) {
    result = min(result, dp[i][j] + num);
  }
  if(num != "0") {
    result = min(result, num + dp[i][j]);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fill(&dp[0][0], &dp[MAX - 1][MAX], "INF");
  dp[0][0] = "";
  for(ll i = 2; i <= 100; i++) {
    for(ll j = 1; j <= 100; j++) {
      if(i >= 2 && dp[i - 2][j - 1] != "INF") {
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 2, j - 1, "1"));
      }
      if(i >= 3 && dp[i - 3][j - 1] != "INF") {
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 3, j - 1, "7"));
      }
      if(i >= 4 && dp[i - 4][j - 1] != "INF") {
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 4, j - 1, "4"));
      }
      if(i >= 5 && dp[i - 5][j - 1] != "INF") {
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 5, j - 1, "2"));
      }
      if(i >= 6 && dp[i - 6][j - 1] != "INF") {
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 6, j - 1, "0"));
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 6, j - 1, "6"));
      }
      if(i >= 7 && dp[i - 7][j - 1] != "INF") {
        dp[i][j] = min(dp[i][j], get_min_dp_value(i - 7, j - 1, "8"));
      }
    }
  }

  cin >> tt;
  while (tt--) {
#ifdef DEBUG
    cout << "\n\tAns: ";
#endif
    solve();
  }

  return 0;
}