#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, answer;
ll C[1010][3];
ll dp[1010][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> C[i][0] >> C[i][1] >> C[i][2];
  }
  answer = INF;

  for(ll t = 0; t < 3; t++) {
    for(ll i = 0; i < N; i++) for (ll j = 0; j < 3; j++) {
      dp[i][j] = INF;
    }
    dp[0][t] = C[0][t];
    for(ll i = 1; i < N; i++) {
      for(ll j = 0; j < 3; j++) {
        if(i == N - 1 && j == t) {
          dp[i][j] = INF;
        } else {
          dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + C[i][j];
        }
      }
    }
    for(ll j = 0; j < 3; j++){ 
      answer = min(answer, dp[N-1][j]);
    }
  }

  cout << answer << '\n';

  return 0;
}